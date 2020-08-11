//
// Created by sacred on 20-8-2.
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

struct T {
    int p, a;
    bool operator<(const T& o) const {
        return p < o.p;
    }
};
T A[5005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> A[i].p >> A[i].a;
    }
    sort(A, A+m);

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        if (n <= 0) break;
        if (n >= A[i].a) {
            n -= A[i].a;
            ans += A[i].p * A[i].a;
        } else {
            ans += A[i].p * n;
            n = 0;
        }
    }
    cout << ans << endl;

    return 0;
}