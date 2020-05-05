//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[25][25][25];

int main(int argc, char **argv)
{
    int w, x, h, q;
    int x1, y1, z1, x2, y2, z2;
    cin >> w >> x >> h >> q;
    
    memset(A, 0x3f, sizeof(A));
    
    while(q--) {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                for (int k = z1; k <= z2; ++k){
                    A[i][j][k] = 0;
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; ++k) {
                if (A[i][j][k]) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}