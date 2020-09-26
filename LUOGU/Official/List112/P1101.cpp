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

char A[110][110], B[110][110];

int d[8][2] = {
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1}
};
int n;
const string target = "yizhong";
bool checkA(int i, int j, int dir)
{
    int nx = i + d[dir][0], ny = j + d[dir][1];
    int c = 1;
    while (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
        if (A[nx][ny] != target[c]) return false;
        nx += d[dir][0], ny += d[dir][1];
        c++;
        if (c == target.size()) return true;
    }
    return false;
}

void fillB(int i, int j, int dir)
{
    int c = 0;
    while (c < target.size()) {
        B[i][j] = target[c++];
        i += d[dir][0], j += d[dir][1];
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> &A[i][1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            B[i][j] = '*';
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] == 'y') {
                for (int d = 0; d < 8; ++d) {
                    if (checkA(i, j, d)) {
                        fillB(i, j, d);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%c", B[i][j]);
        }
        printf("\n");
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}