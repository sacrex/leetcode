//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int N, A[105], ans[105];

int main(int argc, char **argv)
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i]) ans[i]++;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (i) printf(" %d", ans[i]);
        else printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}