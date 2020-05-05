//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[10][10];

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    int cnt = 1;
    A[1][1] = cnt;
    int i = 1, j = 1;
    while(cnt != n * n) {
        while (j+1 <= n && !A[i][j+1]) {
            A[i][++j] = ++cnt;
        }
        while (i+1 <= n && !A[i+1][j]) {
            A[++i][j] = ++cnt;
        }
        while (j-1 >= 1 && !A[i][j-1]) {
            A[i][--j] = ++cnt;
        }
        while (i-1 >= 1 && !A[i-1][j]) {
            A[--i][j] = ++cnt;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%3d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}