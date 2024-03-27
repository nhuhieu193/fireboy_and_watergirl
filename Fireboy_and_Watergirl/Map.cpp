#include "Map.h"
#include <fstream>
#include "texture.h"

Map::Map(string src) {
    ifstream fin(src);
    int x,y;
    while (fin >> x >> y) {
        WallList.push_back({x , y});
    }
    for (int i = 0 ; i < SCREEN_WIDTH ; i++) {
        for (int j = 0 ; j < SCREEN_HEIGHT ; j++) {
            Down[i][j] = -1;
            Up[i][j] = -1;
            Left[i][j] = -1;
            Right[i][j] = -1;
        }
    }
    for (pair <int,int> e : WallList) {
        int x = e.first , y = e.second;
        for (int i = x ; i < x + OBJECT_SIZE ; i++) {
            for (int j = y ; j < y + OBJECT_SIZE ; j++) {
                if (j > 0) Down[i][j - 1] = j;
                if (j < SCREEN_HEIGHT - 1) Up[i][j + 1] = j + 1;
                if (i > 0) Right[i - 1][j] = i;
                if (i < SCREEN_WIDTH - 1) Left[i + 1][j] = i + 1;
            }
        }
    }
    for (int i = 0 ; i < SCREEN_WIDTH ; i++) {
        Up[i][0] = 0;
        Down[i][SCREEN_HEIGHT - 1] = SCREEN_HEIGHT;
    }
    for (int i = 0 ; i < SCREEN_HEIGHT ; i++) {
        Left[0][i] = 0;
        Right[SCREEN_WIDTH - 1][i] = SCREEN_WIDTH;
    }
    for (int row = SCREEN_HEIGHT - 2 ; row >= 0 ; row--) {
        for (int col = 0 ; col < SCREEN_WIDTH ; col++) if (Down[col][row] == -1) Down[col][row] = Down[col][row + 1];
    }
    for (int row = 1 ; row < SCREEN_HEIGHT ; row++) {
        for (int col = 0 ; col < SCREEN_WIDTH ; col++) if (Up[col][row] == -1) Up[col][row] = Up[col][row - 1];
    }
    for (int col = 1 ; col < SCREEN_WIDTH ; col++) {
        for (int row = 0 ; row < SCREEN_HEIGHT ; row++) if (Left[col][row] == -1) Left[col][row] = Left[col - 1][row];
    }
    for (int col = SCREEN_WIDTH - 2 ; col >= 0 ; col--) {
        for (int row = 0 ; row < SCREEN_HEIGHT ; row++) if (Right[row][col] == -1) Right[col][row] = Right[col + 1][row];
    }
}


void Map::Draw() {
    for (pair<int,int> e : WallList) {
        Texture::GetInstance() -> Draw("wall" , e.first , e.second , OBJECT_SIZE , OBJECT_SIZE);
    }
}
