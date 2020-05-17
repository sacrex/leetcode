//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

long long C(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;

    long long ans = 1, t = 1;
    for (int i = 0; i < k; ++i) {
        ans *= (n - i);
        if (i) t *= i;
        //处理越界(例如计算C(30, 20),在30 * 29 * .... * 11时可能就已越界)
        if (ans % t == 0) {
            ans /= t;
            t = 1;
        }
    }
    ans /= (t * k);
    return ans;
}

// (k * C(n, k) (k = 1..n) 的和) * (A[1..n]的和)

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List105/P2415.in");
#endif
    int N = 0, t, sum = 0;
    while(cin >> t) {
        sum += t;
        N++;
    }
    long long ans = 0;
    for (int k = 1; k <= N; ++k) {
        ans += C(N, k) * k / N;
    }
    ans *= sum;
    printf("%lld\n", ans);

    return 0;
}