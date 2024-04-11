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
    freopen("brick.txt" , "w" , stdout);
    freopen("lava.txt" , "w" , stdout);
    freopen("water.txt" , "w" , stdout);
    freopen("greengoo.txt" , "w" , stdout);
    freopen("slide.txt" , "w" , stdout);


    return 0;
}
