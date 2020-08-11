//
// Created by sacred on 20-7-28.
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
#endif

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        if (A[i-1] + A[i] > x) {
            int t = A[i-1] + A[i] - x;
            ans += t;
            if (A[i] >= t) {
                A[i] -= t;
            } else {
                A[i] = 0;
                A[i-1] -= (t - A[i-1]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}