//
// Created by sacred on 20-9-13.
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

int d[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
};

int steps[405000];
int states[400][400];

int pos(int x, int y) { return x * 1000 + y; }
void go(int x, int y) { states[x][y] = 1; }
bool gone(int x, int y) {return states[x][y]; }

char A[400][400];

int T1[128], T2[128]; //装置位置

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List112/P1825.in");
//    time_t start_time = time(NULL);
#endif
    int N, M;
    scanf("%d%d", &N, &M);
    int sx, sy;

    memset(steps, 0x3f, sizeof(steps));

    for (int i = 1; i <= N; ++i) {
        scanf("%s", &A[i][1]);
        for (int j = 1; j <= M; ++j) {
            if (A[i][j] == '@') {
                sx = i, sy = j;
            } else if (isalpha(A[i][j])){
                if (T1[A[i][j]] == 0) {
                    T1[A[i][j]] = pos(i, j);
                } else {
                    T2[A[i][j]] = pos(i, j);
                }
            }
        }
    }

    queue<int> q;
    q.push(pos(sx, sy));
    steps[pos(sx, sy)] = 0;
    go(sx, sy);

    int ans = 100000000;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        int y = x % 1000;
        x = x - y;
        x /= 1000;


        for (int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx < 1 || nx > N || ny < 1 || ny > M
                || gone(nx, ny) || A[nx][ny] == '#') {
                ;
            } else {
                if (A[nx][ny] == '.') {
                    q.push(pos(nx, ny));
                    go(nx, ny);

                    steps[pos(nx, ny)] = steps[pos(x, y)] + 1;

                } else if (isalpha(A[nx][ny])) {
                    if (T1[A[nx][ny]] == pos(nx, ny)) {
                        //T1 -> T2
                        int t2 = T2[A[nx][ny]];
                        int t2_y = t2 % 1000, t2_x = (t2 - t2_y) / 1000;

                        q.push(pos(t2_x, t2_y));

                        steps[pos(t2_x, t2_y)] = steps[pos(x, y)] + 1;

                        go(nx, ny);

                    } else if (T2[A[nx][ny]] == pos(nx, ny)) {
                        // T2 -> T1
                        int t1 = T1[A[nx][ny]];
                        int t1_y = t1 % 1000, t1_x = (t1 - t1_y) / 1000;

                        q.push(pos(t1_x, t1_y));

                        go(nx, ny);

                        steps[pos(t1_x, t1_y)] = steps[pos(x, y)] + 1;
                    }
                } else if (A[nx][ny] == '=') {
                    ans = steps[pos(x, y)] + 1;
                }
            }
        }
    }
    printf("%d\n", ans);

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}