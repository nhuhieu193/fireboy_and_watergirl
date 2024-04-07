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
//    freopen("brick.txt" , "w" , stdout);
//    freopen("lava.txt" , "w" , stdout);
//    freopen("water.txt" , "w" , stdout);
    freopen("greengoo.txt" , "w" , stdout);
//    get(0,390,570,600);
    get(630,720,570,600);
    get(420,720,450,480);
//    get(600,630,570,600);
//    get(720,900,570,600);

    return 0;
}
