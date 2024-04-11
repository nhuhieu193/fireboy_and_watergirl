#include <iostream>
#define f(i,a,b) for (int i = a ; i <= b ; i++)
using namespace std;

void g(int l , int r , int u , int v) {
    for (int x = l * 10 ; x < r * 10 ; x += 30) {
        for (int y = u * 10 ; y < v * 10; y += 30) {
            cout << x << " " << y << '\n';
        }
    }
}

int main()
{
    freopen("brick.txt" , "w" , stdout);
//    freopen("lava.txt" , "w" , stdout);
//    freopen("water.txt" , "w" , stdout);
//    freopen("greengoo.txt" , "w" , stdout);
//    freopen("slide.txt" , "w" , stdout);

    g(9,21,48,51);
    g(72,81,48,51);

    g(21,72,57,60);
    g(21,24,12,57);
    g(69,72,12,57);
    g(45,48,54,57);
    g(45,48,42,51);
    g(45,48,30,39);
    g(45,48,18,27);
    g(42,51,15,18);

    g(24,33,45,48);
    g(60,69,45,48);
    g(63,69,33,36);
    g(24,30,33,36);
    g(63,69,21,24);
    g(24,30,21,24);

    g(27,30,9,12);
    g(6,9,9,12);
    g(63,66,9,12);
    g(81,84,9,12);

//    g(66,81,9,12);

//    g(0,21,57,60);
//    g(72,90,57,60);

    cout << "blue" << " " << 60 << " " << 390 << " " << 510 << " " << 1 << " " << 260 << " " << 440 << '\n';
    cout << "green" << " " << -60 << " " << 450 << " " << 390 << " " << 1 << " " << 655 << " " << 320 << '\n';
    cout << "yellow" << " " << 60 << " " << 390 << " " << 270 << " " << 1 << " " << 260 << " " << 200 << '\n';

    return 0;
}
