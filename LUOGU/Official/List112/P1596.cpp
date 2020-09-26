//
// Created by sacred on 20-9-24.
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
int N, M;
int d[8][2] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

void dfs(int i, int j)
{
    if (i < 1 || i > N || j < 1 || j > M) return;
    if (A[i][j] == 'W') A[i][j] = 'X';
    for (int dir = 0; dir < 8; ++dir) {
        int nx = d[dir][0] + i, ny = d[dir][1] + j;
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
            if (A[nx][ny] == 'W') dfs(nx, ny);
        }
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> &A[i][1]; //不是从第0列开始

    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i][j] == 'W') {
                cnt += 1;
                dfs(i, j);
            }
        }
    }
    cout << cnt;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}