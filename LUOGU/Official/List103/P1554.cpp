//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int main(int argc, char **argv)
{
    int M, N, ans[20] = {0};
    cin >> M >> N;
    for (int i = M; i <= N; ++i) {
        int k = i;
        while(k) {
            ans[k % 10]++;
            k /= 10;
        }
    }

    for (int i = 0; i <= 9; ++i) {
        if (i) printf(" %d", ans[i]);
        else printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}