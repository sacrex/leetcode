//
// Created by sacred on 20-7-2.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//buf数组缓存数组（预读到buf数组）
char Buf[1 << 16], *p = Buf, *q = Buf;
#define Getchar() (p == q && (q = (p = Buf) + fread(Buf, 1, 1 << 16, stdin), p == q) ? EOF : *p++)
inline int Read() {
    char ch = Getchar();
    int x = 0,f = 1;
    while (ch < '0'|| ch > '9') {
        if(ch=='-')
            f=-1;
        ch = Getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x=10 * x + ch - '0';
        ch = Getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

ll A[25][25];
int Bx, By;

bool check (int i, int j, int x, int y) {
    if (i == 0 && j == 0 || i == x && j == y) return 0;
    if (x - 2 >= 0 && y - 1 >= 0 && i == x - 2 && j == y - 1) return 0;
    if (x - 1 >= 0 && y - 2 >= 0 && i == x - 1 && j == y - 2) return 0;
    if (x + 1 <= Bx && y - 2 >= 0 && i == x + 1 && j == y - 2) return 0;
    if (x + 2 <= Bx && y - 1 >= 0 && i == x + 2 && j == y - 1) return 0;

    if (x + 2 <= Bx && y + 1 <= By && i == x + 2 && j == y + 1) return 0;
    if (x + 1 <= Bx && y + 2 <= By && i == x + 1 && j == y + 2) return 0;
    if (x - 1 >= 0 && y + 2 <= By && i == x - 1 && j == y + 2) return 0;
    if (x - 2 >= 0 && y + 1 <= By && i == x - 2 && j == y + 1) return 0;
    return 1;
}

//优化的话使用滚动数组

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int Cx, Cy;
    cin >> Bx >> By >> Cx >> Cy;

    int flag = 1;
    for (int j = 1; j <= By; ++j) {
        if (flag && check(0, j, Cx, Cy)) {
            A[0][j] = 1;
        } else {
            flag = 0;
        }
    }

    flag = 1;
    for (int i = 1; i <= Bx; ++i) {
        if (flag && check(i, 0, Cx, Cy)) {
            A[i][0] = 1;
        } else {
            flag = 0;
        }
    }

    for (int i = 1; i <= Bx; ++i) {
        for (int j = 1; j <= By; ++j) {
            if (check(i, j, Cx, Cy)) {
                A[i][j] = A[i][j-1] + A[i-1][j];
            }
        }
    }

    cout << A[Bx][By] << endl;

    return 0;
}