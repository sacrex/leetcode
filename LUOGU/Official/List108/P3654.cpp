//
// Created by sacred on 20-6-27.
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

char A[105][105];
int R, C, K;

int rowCnt(char a[][105], int i, int j) {
    int cnt = 0;
    while (j <= C && a[i][j] == '.') cnt++, j++;
    return cnt;
}

int colCnt(char a[][105], int i, int j) {
    int cnt = 0;
    while (i <= R && a[i][j] == '.') cnt++, i++;
    return cnt;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    cin >> R >> C >> K;
    for (int i = 1; i <= R; ++i) {
        cin >> &A[i][1];
    }

    int ans = 0;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (A[i][j] == '#') continue;
            assert(A[i][j] == '.');

            if (K == 1) {
                ans++;
            } else {
                if (rowCnt(A, i, j) >= K) ans++;
                if (colCnt(A, i, j) >= K) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}