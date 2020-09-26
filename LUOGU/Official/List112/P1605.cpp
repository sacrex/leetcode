//
// Created by sacred on 20-9-8.
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

int N, M, T, SX, SY, FX, FY;

int d[10][10];
int D[4][2] = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
};

int ans = 0;

void dfs(int sx, int sy, int dir)
{
    int nx = sx + D[dir][0], ny = sy + D[dir][1];
    if (d[nx][ny] == -1) return;
    if (d[nx][ny] >= 1) return;
    if (nx == FX && ny == FY) {
        ans++;
        return;
    }

    d[nx][ny] = 1;
    for (int i = 0; i < 4; ++i) {
        dfs(nx, ny, i);
    }
    d[nx][ny] = 0; //回溯
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    memset(d, 0, sizeof(d));
    cin >> N >> M >> T >> SX >> SY >> FX >> FY;
    for (int i = 1; i <= T; ++i) {
        int j,k;
        cin >> j >> k;
        d[j][k] = -1;

        //终点存在障碍物，直接返回
        if (j == FX && k == FY) {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 0; i <= N + 1; ++i) {
        d[i][0] = d[i][M+1] = -1;
    }
    for (int j = 0; j <= M + 1; ++j) {
        d[0][j] = d[N+1][j] = -1;
    }

    d[SX][SY] = 1;
    for (int i = 0; i < 4; ++i) {
        dfs(SX, SY, i);
    }

    printf("%d\n", ans);

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}