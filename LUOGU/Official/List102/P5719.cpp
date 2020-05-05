//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int main(int argc, char **argv)
{
    int n, k, A = 0, B = 0;
    cin >> n >> k;

    for (int i = 1; i <= (n / k); ++i) {
        A += k * i;
    }
    B = (1 + n) * n / 2 - A;

    int A_cnt = n / k;
    int B_cnt = n - n / k;

    if (A_cnt == 0) {
        printf("0.0 ");
    } else {
        printf("%.1f ", A * 1.0 / A_cnt);
    }

    if (B_cnt == 0) {
        printf("0.0\n");
    } else {
        printf("%.1f\n", B * 1.0 / B_cnt);
    }

    return 0;
}