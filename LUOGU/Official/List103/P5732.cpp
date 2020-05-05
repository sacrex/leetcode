//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[25][25];

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    A[1][1] = 1;
    A[2][1] = A[2][2] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) A[i][j] = 1;
            else {
                A[i][j] = A[i-1][j-1] + A[i-1][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1) {
                printf("1");
            } else {
                printf(" %d", A[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}