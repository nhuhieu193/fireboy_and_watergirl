#include "Map.h"
#include <fstream>
#include "texture.h"
#include <algorithm>

Map::Map(string Stage) {
    for (int i = 0 ; i < __SCREEN_WIDTH ; i++) {
        for (int j = 0 ; j < __SCREEN_HEIGHT ; j++) {
            Down[i][j] = -1;
            Up[i][j] = -1;
            Left[i][j] = -1;
            Right[i][j] = -1;
        }
    }
    InputBrick("maplevel/Stage" + Stage + "/brick.txt");
    InputLava("maplevel/Stage" + Stage + "/lava.txt");
    InputWater("maplevel/Stage" + Stage + "/water.txt");
    InputGreenGoo("maplevel/Stage" + Stage + "/greengoo.txt");
    InputSlide("maplevel/Stage" + Stage + "/slide.txt");

    for (int i = 0 ; i < __SCREEN_WIDTH ; i++) {
        Up[i][0] = 0;
        Down[i][__SCREEN_HEIGHT - 1] = __SCREEN_HEIGHT;
    }
    for (int i = 0 ; i < __SCREEN_HEIGHT ; i++) {
        Left[0][i] = 0;
        Right[__SCREEN_WIDTH - 1][i] = __SCREEN_WIDTH;
    }

    SaveRawMap();

    for (int row = __SCREEN_HEIGHT - 2 ; row >= 0 ; row--) {
        for (int col = 0 ; col < __SCREEN_WIDTH ; col++) if (Down[col][row] == -1) Down[col][row] = Down[col][row + 1];
    }
    for (int row = 1 ; row < __SCREEN_HEIGHT ; row++) {
        for (int col = 0 ; col < __SCREEN_WIDTH ; col++) if (Up[col][row] == -1) Up[col][row] = Up[col][row - 1];
    }
    for (int col = 1 ; col < __SCREEN_WIDTH ; col++) {
        for (int row = 0 ; row < __SCREEN_HEIGHT ; row++) if (Left[col][row] == -1) Left[col][row] = Left[col - 1][row];
    }
    for (int col = __SCREEN_WIDTH - 2 ; col >= 0 ; col--) {
        for (int row = 0 ; row < __SCREEN_HEIGHT ; row++) if (Right[col][row] == -1) Right[col][row] = Right[col + 1][row];
    }
}

bool Map::OnGround(const Vector2D& vect) {
    int x = vect.X , y = vect.Y;
    for (int i = x ; i < x + __CHARACTER_WIDTH - 1; i++) if (y + __CHARACTER_HEIGHT == Down[i][y]) return true;
    return false;
}

void Map::Update(double X , double Y , double U , double V) {
    TurnBackRawMap();
    for (int i = 0 ; i < (int)SlideList.size() ; i++) {
        if (SlideList[i].CollideWithButtonList(X , Y , U , V)) {
            currentSlideFrames[i]++;
            if (SlideList[i].CollideWithCharacter(currentSlideFrames[i] , X , Y) || SlideList[i].CollideWithCharacter(currentSlideFrames[i] , U , V)) currentSlideFrames[i]--;
            if (currentSlideFrames[i] > SlideList[i].FramesSlide) currentSlideFrames[i] = SlideList[i].FramesSlide;
        }else {
            currentSlideFrames[i]--;
            if (SlideList[i].CollideWithCharacter(currentSlideFrames[i] , X , Y) || SlideList[i].CollideWithCharacter(currentSlideFrames[i] , U , V)) currentSlideFrames[i]++;
            if (currentSlideFrames[i] < 0) currentSlideFrames[i] = 0;
        }
        UpdateCurrentSlideMap(SlideList[i].x + SlideList[i].VelocitySlide * currentSlideFrames[i] , SlideList[i].y);
    }
    UpdateEntireMap();
}

void Map::Draw() {
    for (int id = 0 ; id < (int)SlideList.size() ; id++) {
        Texture::GetInstance() -> Draw(SlideList[id].SlideName + "Slide" , SlideList[id].x + SlideList[id].VelocitySlide * currentSlideFrames[id] , SlideList[id].y , 90 , 15);
        for (int i = 0 ; i < SlideList[id].numButtons ; i++) {
            Texture::GetInstance() -> Draw(SlideList[id].SlideName + "Button" , SlideList[id].ButtonList[i].first , SlideList[id].ButtonList[i].second + SlideList[id].currentFramesButton[i] * SlideList[id].VelocityButton, 29 , 10);
        }
    }
    for (pair<int,int> e : BrickList) {
        Texture::GetInstance() -> Draw("brick" , e.first , e.second , __OBJECT_SIZE , __OBJECT_SIZE);
    }
    for (pair<int,int> e : LavaList) {
        Texture::GetInstance() -> DrawLiquid("lava" , e.first , e.second , __OBJECT_SIZE , __OBJECT_SIZE , (SDL_GetTicks() / LiquidAnimationSpeed) % numFrames);
    }
    for (pair<int,int> e : WaterList) {
        Texture::GetInstance() -> DrawLiquid("water" , e.first , e.second , __OBJECT_SIZE , __OBJECT_SIZE , (SDL_GetTicks() / LiquidAnimationSpeed) % numFrames);
    }
    for (pair<int,int> e : GreenGooList) {
        Texture::GetInstance() -> DrawLiquid("greengoo" , e.first , e.second , __OBJECT_SIZE , __OBJECT_SIZE , (SDL_GetTicks() / LiquidAnimationSpeed) % numFrames);
    }
}

void Map::UpdateEntireMap() {
    for (int col = 1 ; col < __SCREEN_WIDTH ; col++) {
        for (int row : updateRow) if (Left[col][row] == -1) Left[col][row] = Left[col - 1][row];
    }
    for (int col = __SCREEN_WIDTH - 2 ; col >= 0 ; col--) {
        for (int row : updateRow) if (Right[col][row] == -1) Right[col][row] = Right[col + 1][row];
    }
    for (int row = __SCREEN_HEIGHT - 2 ; row >= 0 ; row--) {
        for (int col : updateCol) if (Down[col][row] == -1) Down[col][row] = Down[col][row + 1];
    }
    for (int row = 1 ; row < __SCREEN_HEIGHT ; row++) {
        for (int col : updateCol) if (Up[col][row] == -1) Up[col][row] = Up[col][row - 1];
    }
}

void Map::UpdateCurrentSlideMap(int x , int y) {
    for (int i = x ; i < x + 90 ; i++) {
        for (int j = y ; j < y + 15 ; j++) {
            if (j > 0) Down[i][j - 1] = j;
            if (j < __SCREEN_HEIGHT - 1) Up[i][j + 1] = j + 1;
            if (i > 0) Right[i - 1][j] = i;
            if (i < __SCREEN_WIDTH - 1) Left[i + 1][j] = i + 1;
        }
    }
}

void Map::TurnBackRawMap() {
    for (int col = 1 ; col < __SCREEN_WIDTH ; col++) {
        for (int row : updateRow) Left[col][row] = PreLeft[col][row];
    }
    for (int col = __SCREEN_WIDTH - 2 ; col >= 0 ; col--) {
        for (int row : updateRow) Right[col][row] = PreRight[col][row];
    }
    for (int row = __SCREEN_HEIGHT - 2 ; row >= 0 ; row--) {
        for (int col : updateCol) Down[col][row] = PreDown[col][row];
    }
    for (int row = 1 ; row < __SCREEN_HEIGHT ; row++) {
        for (int col : updateCol) Up[col][row] = PreUp[col][row];
    }
}

bool Map::CollideWithLava(double x , double y , int width , int height) {
    for (pair<int,int> e : LavaList) {
        if (e.first >= x + width || e.first + __OBJECT_SIZE <= x) continue;
        if (e.second + 1 >= y + height || e.second + 16 <= y) continue;
        return true;
    }
    return false;
}

bool Map::CollideWithWater(double x , double y , int width , int height) {
    for (pair<int,int> e : WaterList) {
        if (e.first >= x + width || e.first + __OBJECT_SIZE <= x) continue;
        if (e.second + 1 >= y + height || e.second + 16 <= y) continue;
        return true;
    }
    return false;
}

bool Map::CollideWithGreenGoo(double x , double y , int width , int height) {
    for (pair<int,int> e : GreenGooList) {
        if (e.first >= x + width || e.first + __OBJECT_SIZE <= x) continue;
        if (e.second + 1 >= y + height || e.second + 16 <= y) continue;
        return true;
    }
    return false;
}

void Map::InputSlide(string src) {
    ifstream fin(src);
    if (!fin) return;
    string name;
    Slide currentSlide;
    while (fin >> name) {
        currentSlide.SlideName = name;
        fin >> currentSlide.Direction;
        fin >> currentSlide.x >> currentSlide.y;
        fin >> currentSlide.numButtons;
        for (int i = 0 ; i < currentSlide.numButtons ; i++) {
            double x,y;
            fin >> x >> y;
            currentSlide.ButtonList.push_back({x , y});
            currentSlide.currentFramesButton.push_back(0);
        }
        currentSlide.FramesSlide = FPS * SlideTime / 1000;
        currentSlide.FramesButton = FPS * ButtonTime / 1000;
        currentSlide.VelocitySlide = 1.0 * currentSlide.Direction / currentSlide.FramesSlide;
        currentSlide.VelocityButton = 1.0 * 8 / currentSlide.FramesButton;
        SlideList.push_back(currentSlide);
        currentSlideFrames.push_back(0);
        for (int col = min(currentSlide.x , currentSlide.x + currentSlide.Direction) ; col < max(currentSlide.x + 90 , currentSlide.x + 90 + currentSlide.Direction) ; col++) {
            updateCol.push_back(col);
        }
        for (int row = currentSlide.y ; row < currentSlide.y + 15 ; row++) {
            updateRow.push_back(row);
        }
    }
    sort(updateCol.begin() , updateCol.end());
    updateCol.resize(unique(updateCol.begin() , updateCol.end()) - updateCol.begin());
    sort(updateRow.begin() , updateRow.end());
    updateRow.resize(unique(updateRow.begin() , updateRow.end()) - updateRow.begin());
}

void Map::InputLava(string src) {
    ifstream fin(src);
    if (!fin) return;
    int x,y;
    while (fin >> x >> y) {
        LavaList.push_back({x , y});
    }
    for (pair <int,int> e : LavaList) {
        int x = e.first , y = e.second;
        for (int i = x ; i < x + __OBJECT_SIZE ; i++) {
            for (int j = y + 16; j < y + __OBJECT_SIZE ; j++) {
                if (j > 0) Down[i][j - 1] = j;
                if (j < __SCREEN_HEIGHT - 1) Up[i][j + 1] = j + 1;
                if (i > 0) Right[i - 1][j] = i;
                if (i < __SCREEN_WIDTH - 1) Left[i + 1][j] = i + 1;
            }
        }
    }
}

void Map::InputWater(string src) {
    ifstream fin(src);
    if (!fin) return;
    int x,y;
    while (fin >> x >> y) {
        WaterList.push_back({x , y});
    }
    for (pair <int,int> e : WaterList) {
        int x = e.first , y = e.second;
        for (int i = x ; i < x + __OBJECT_SIZE ; i++) {
            for (int j = y + 16; j < y + __OBJECT_SIZE ; j++) {
                if (j > 0) Down[i][j - 1] = j;
                if (j < __SCREEN_HEIGHT - 1) Up[i][j + 1] = j + 1;
                if (i > 0) Right[i - 1][j] = i;
                if (i < __SCREEN_WIDTH - 1) Left[i + 1][j] = i + 1;
            }
        }
    }
}

void Map::InputGreenGoo(string src) {
    ifstream fin(src);
    if (!fin) return;
    int x,y;
    while (fin >> x >> y) {
        GreenGooList.push_back({x , y});
    }
    for (pair <int,int> e : GreenGooList) {
        int x = e.first , y = e.second;
        for (int i = x ; i < x + __OBJECT_SIZE ; i++) {
            for (int j = y + 16; j < y + __OBJECT_SIZE ; j++) {
                if (j > 0) Down[i][j - 1] = j;
                if (j < __SCREEN_HEIGHT - 1) Up[i][j + 1] = j + 1;
                if (i > 0) Right[i - 1][j] = i;
                if (i < __SCREEN_WIDTH - 1) Left[i + 1][j] = i + 1;
            }
        }
    }
}

void Map::InputBrick(string src) {
    ifstream fin(src);
    if (!fin) return;
    int x,y;
    while (fin >> x >> y) {
        BrickList.push_back({x , y});
    }
    for (pair <int,int> e : BrickList) {
        int x = e.first , y = e.second;
        for (int i = x ; i < x + __OBJECT_SIZE ; i++) {
            for (int j = y ; j < y + __OBJECT_SIZE ; j++) {
                if (j > 0) Down[i][j - 1] = j;
                if (j < __SCREEN_HEIGHT - 1) Up[i][j + 1] = j + 1;
                if (i > 0) Right[i - 1][j] = i;
                if (i < __SCREEN_WIDTH - 1) Left[i + 1][j] = i + 1;
            }
        }
    }
}

void Map::SaveRawMap() {
    for (int i = 0 ; i < __SCREEN_WIDTH ; i++) {
        for (int j = 0 ; j < __SCREEN_HEIGHT ; j++) {
            PreUp[i][j] = Up[i][j];
            PreDown[i][j] = Down[i][j];
            PreLeft[i][j] = Left[i][j];
            PreRight[i][j] = Right[i][j];
        }
    }
}
