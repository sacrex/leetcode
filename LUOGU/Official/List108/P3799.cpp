//
// Created by sacred on 20-7-1.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

long long C(int n, int k = 2) {
    return (n * n - n) / 2;
}

inline int Read() {
    char ch = getchar();
    int x = 0,f = 1;
    while (ch < '0'|| ch > '9') {
        if(ch=='-')
            f=-1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x=10 * x + ch - '0';
        ch = getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

const ll MOD = 1000000000 + 7;

int cnt[5005] = {0};
int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cnt[Read()]++;
    }

    ll ans = 0;
    for (int i = 2; i <= 5000; ++i) {
        if (cnt[i] < 2) continue;

        ll a = C(cnt[i]);
        ll b = 0;

        int l = 0, r = i;
        while (true) {
            l++;
            r--;
            if (l > r) break;
            if (cnt[l] == 0 && cnt[r] == 0) continue;
            if (l == r) {
                b += C(cnt[l]);
            } else {
                b += cnt[l] * cnt[r];
            }
        }
        ans += (a * (b % MOD)) % MOD;
    }

    printf("%lld\n", ans % MOD);
    return 0;
}