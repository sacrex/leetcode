//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[105][105];

//火把位置相对与(x, y)
int torch[13][2] = {
        {-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0},
        {0, -2}, {0, -1}, {0, 1}, {0, 2},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

//萤石左上角和右下角
int cand[2][2] = {
        {-2, -2}, {2, 2}
};

bool check(int n, int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= n) return true;
    return false;
}

int main(int argc, char **argv)
{
    int n, m, k;
    cin >> n >> m >> k;
    memset(A, 0x3f, sizeof(A));

    while (m--) {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 13; ++i) {
            int nx = torch[i][0] + x, ny = torch[i][1] + y;
            if (check(n, nx, ny)) {
                A[nx][ny] = 0;
            }
        }
    }
    while(k--) {
        int x, y;
        cin >> x >> y;
        int lx = cand[0][0] + x, ly = cand[0][1] + y;
        int rx = cand[1][0] + x, ry = cand[1][1] + y;
        for (int i = lx; i <= rx; ++i) {
            for (int j = ly; j <= ry; ++j) {
                if (check(n, i, j)) {
                    A[i][j] = 0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}