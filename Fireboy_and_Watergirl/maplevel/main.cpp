#include <iostream>
#define f(i,a,b) for (int i = a ; i <= b ; i++)
using namespace std;

void get(int l , int r , int u , int v) {
    for (int x = l ; x < r ; x += 30) {
        for (int y = u ; y < v ; y += 30) {
            cout << x << " " << y << '\n';
        }
    }
}

int main()
{
    freopen("stage1.txt" , "w" , stdout);
    get(0 , 900 , 570 , 600);
    get(420 , 690 , 510 , 570);
    get(600 , 780 , 450 , 510);
    get(720 , 840 , 390 , 450);
    get(810 , 900 , 330 , 390);
    get(660 , 750 , 270 , 300);
    get(480 , 510 , 300 , 330);
    get(180 , 240 , 450 , 480);
    get(180 , 210 , 420 , 450);
    get(0 , 60 , 360 , 390);
    get(0 , 30 , 300 , 360);
    get(90 , 120 , 240 , 270);
    get(230 , 290 , 180 , 210);
    get(390 , 900 , 120 , 150);

    return 0;
}
