//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[1100][1100];

void dfs(int left, int right, int up, int down)
{
    if (left >= right && up >= down) {
        A[up][left] = 1;
        return;
    }
    int mid1 = (left + right) / 2, mid2 = (up + down) / 2;
    dfs(mid1+1, right, up, mid2);
    dfs(left, mid1, mid2+1, down);
    dfs(mid1+1, right, mid2+1, down);
}


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int n;
    cin >> n;

    dfs(1, 1<<n, 1, 1<<n);

    for (int i = 1; i <= (1<<n); ++i) {
        for (int j = 1; j <= (1<<n); ++j) {
            if (j != 1) printf(" ");
            if (A[i][j]) printf("1"); else printf("0");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
