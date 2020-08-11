//
// Created by sacred on 20-7-22.
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

const int N = 11;
char A[1<<N][1<<N] = {' '}; //2^N * 2^N次
int n;

//以(x0, y0)为左上角，绘制一个2x4的矩阵（里面是一个三角）
void paint(int x0, int y0)
{
    A[x0][y0+1] = '/';
    A[x0][y0+2] = '\\';
    A[x0+1][y0] = '/';
    A[x0+1][y0+1] = '_';
    A[x0+1][y0+2] = '_';
    A[x0+1][y0+3] = '\\';
}

// 以(x0, y0)为左上角，w×l的矩形按（hori, vert）向量平移
void transfer(int x0, int y0, int w, int l, int hori, int vert)
{
    int x, y;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < l; ++j) {
            x = x0 + i, y = y0 + j;
            A[x+vert][y+hori] = A[x][y];
            if (y > (1 << n) + x) break;
        }
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    cin >> n;

    //先以(1, 2^n-1)为左上角，构造一个2×4的矩形（包含小三角）
    int x0 = 1, y0 = (1 << n) - 1;
    paint(x0, y0); //以(1, 2^n-1)为左上角，矩形为 宽2x长4

    //然后构造n=2,n=3,...的情况
    int w = 2, l = 4;
    for (int i = 2; i <= n; ++i) {
        //通过对小三角的平移，构造大一级的三角形
        transfer(x0, y0, w, l, -w, w); //左下
        transfer(x0, y0, w, l, w, w);  //右下

        y0 = y0 - w;
        w = w * 2;
        l = l * 2;
    }

    //output
    for (int i = 1; i <= (1 << n); ++i) {
        int j = 1;
        while(j <= (1 << (n+1)) + 1 ) {
            if (j > (1 << n) + i) {
                cout << '\n';
                break;
            }
            if (A[i][j] == 0) cout << ' '; else cout << A[i][j];
            j++;
        }
    }

    return 0;
}