//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

char A[105][105];

int dir[8][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char t;
            cin >> t;
            A[i][j] = t;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i][j] == '*') printf("*");
            else {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                        if (A[nx][ny] == '*') cnt++;
                    }
                }
                printf("%d", cnt);
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}