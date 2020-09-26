//
// Created by sacred on 20-9-11.
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

int A[40][40], n;
int d[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
};

//只要向4周走都碰到1,表示在圈内,返回true,
// 并且不管是否在圈内都填充走过数为-1
bool check(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n) return false;
    if (A[i][j] == 1 || A[i][j] == -1) return true;

    A[i][j] = -1;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = i + d[dir][0], ny = j + d[dir][1];
        if (!check(nx, ny)) return false;
    }
    return true;
}

void dfs(int i, int j)
{
    //对填充为2或1的直接返回
    if (A[i][j] == 2 || A[i][j] == 1) return;

    A[i][j] = 2;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = i + d[dir][0], ny = j + d[dir][1];
        dfs(nx, ny);
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] == 0 && check(i, j)) {
                dfs(i, j);
                goto done;
            }
        }
    }
done:
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%-2d", A[i][j] == -1 ? 0 : A[i][j]);
        }
        printf("\n");
    }


#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}