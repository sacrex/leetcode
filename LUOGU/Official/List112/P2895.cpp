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

// A[i][j] == -1: 一定不会被砸到
// A[i][j] == t: 在t时刻以及之后，不能走
int A[305][305], N, F[305][305];  //F[i][j]记录已走过的点
int ans = -1;
int d[4][2] = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

struct P {
    int x, y, t;
    P(int x = 0, int y = 0, int t = 0): x(x), y(y), t(t){}
};

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    memset(A, -1, sizeof(A));
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        if (A[x][y] == -1) A[x][y] = t;
        else {
            A[x][y] = min(A[x][y], t);
        }

        if (x-1 >= 0) A[x-1][y] = (A[x-1][y] == -1) ? t : min(A[x-1][y], t);
        if (y-1 >= 0) A[x][y-1] = (A[x][y-1] == -1) ? t : min(A[x][y-1], t);
        if (x+1 <= 300) A[x+1][y] = (A[x+1][y] == -1) ? t : min(A[x+1][y], t);
        if (y+1 <= 300) A[x][y+1] = (A[x][y+1] == -1) ? t : min(A[x][y+1], t);
    }

    queue<P> q;
    q.push(P());
    F[0][0] = 1;
    int ans = -1;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        if (A[p.x][p.y] == -1) {
            cout << p.t;
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = d[dir][0] + p.x, ny = d[dir][1] + p.y;
            //NOTE: 可以走的位置不只是限制在[0,300],只是流星砸到的只在[0,300]中。
            //所以这里的nx，ny可以为稍微比300大。
            if (nx >= 0 && nx <= 304 && ny >= 0 && ny <= 304) {
                if (A[nx][ny] == -1) {
                    cout << p.t + 1;
                    return 0;
                }

                if (F[nx][ny]) continue;

                if (A[nx][ny] > p.t + 1) {
                    q.push(P(nx, ny, p.t+1));
                    F[nx][ny] = 1;
                }
            }
        }
    }
    cout << ans;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}