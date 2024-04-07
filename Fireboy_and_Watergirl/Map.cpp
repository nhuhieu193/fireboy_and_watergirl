#include "Map.h"
#include <fstream>
#include "texture.h"

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

    for (int i = 0 ; i < __SCREEN_WIDTH ; i++) {
        Up[i][0] = 0;
        Down[i][__SCREEN_HEIGHT - 1] = __SCREEN_HEIGHT;
    }
    for (int i = 0 ; i < __SCREEN_HEIGHT ; i++) {
        Left[0][i] = 0;
        Right[__SCREEN_WIDTH - 1][i] = __SCREEN_WIDTH;
    }
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


void Map::Draw() {
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

bool Map::CollideWithLava(double x , double y , int width , int height) {
    for (pair<int,int> e : LavaList) {
        if (e.first > x + width || e.first + __OBJECT_SIZE < x) continue;
        if (e.second + 1 > y + height || e.second + 16 < y) continue;
        return true;
    }
    return false;
}

bool Map::CollideWithWater(double x , double y , int width , int height) {
    for (pair<int,int> e : WaterList) {
        if (e.first > x + width || e.first + __OBJECT_SIZE < x) continue;
        if (e.second + 1 > y + height || e.second + 16 < y) continue;
        return true;
    }
    return false;
}

bool Map::CollideWithGreenGoo(double x , double y , int width , int height) {
    for (pair<int,int> e : GreenGooList) {
        if (e.first > x + width || e.first + __OBJECT_SIZE < x) continue;
        if (e.second + 1 > y + height || e.second + 16 < y) continue;
        return true;
    }
    return false;
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

