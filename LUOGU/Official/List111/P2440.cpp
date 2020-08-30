//
// Created by sacred on 20-8-16.
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

int A[100005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    int N, K, l = 0, r = -1;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (A[i] > r) r = A[i];
    }

    int ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (m == 0) break;

        int sum = 0;
        for (int i = 1; i <= N; ++i) {
            sum += A[i] / m;
        }
        if (sum >= K) {
            ans = max(ans, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << endl;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}