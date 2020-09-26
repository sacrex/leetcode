//
// Created by sacred on 20-8-31.
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

int A[405][405];
int n, m;

int d[8][2] = {
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1},

        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1}
};

bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    int x, y;
    cin >> n >> m >> x >> y;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            A[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    A[x][y] = 0;

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (int dir = 0; dir < 8; ++dir) {
            int x1 = d[dir][0] + p.first, y1 = d[dir][1] + p.second;
            if (check(x1, y1) && A[x1][y1] == -1) {
                A[x1][y1] = A[p.first][p.second] + 1;
                q.push({x1, y1});
            }
        }
    }

    //output
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%-5d", A[i][j]);
        }
        printf("\n");
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}