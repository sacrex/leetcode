//
// Created by sacred on 20-8-15.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//buf数组缓存数组（预读到buf数组）
char Buf[1 << 16], *p = Buf, *q = Buf;
#define Getchar() (p == q && (q = (p = Buf) + fread(Buf, 1, 1 << 16, stdin), p == q) ? EOF : *p++)
inline int Read() {
    char ch = Getchar();
    int x = 0,f = 1;
    while (ch < '0'|| ch > '9') {
        if(ch=='-')
            f=-1;
        ch = Getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x=10 * x + ch - '0';
        ch = Getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

ll A[1000005], sum[1000005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    ll N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    sort(A+1, A+N+1);
    for (int i = 1; i <= N; ++i) {
        sum[i] = sum[i-1] + A[i];
    }

    ll ans = 0;
    int l = 1, r = N;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (sum[N] - sum[mid - 1] < M) {
            r = mid - 1;
        } else {
            ll left = sum[N] - sum[mid - 1] - M;
            ll p = left  / (N - mid + 1);
            if (p >= A[mid-1] && p <= A[mid]) {
                ans = max(p, ans);
                l = mid + 1; //满足的情况下，往右走
            } else if (p > A[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    cout << ans << endl;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}