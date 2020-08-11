//
// Created by sacred on 20-7-8.
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

ll A[25][25][25];
bool fg[25][25][25];

ll f(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1LL;

    if (a > 20 || b > 20 || c > 20) return f(20, 20, 20);

    if (fg[a][b][c]) {
        return A[a][b][c];
    }

    if (a < b && b < c) {
        ll t = f(a, b, c-1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
        fg[a][b][c] = true;
        A[a][b][c] = t;
        return t;
    }

    ll t = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
    fg[a][b][c] = true;
    A[a][b][c] = t;
    return t;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    ll a, b, c;
    while(scanf("%lld%lld%lld", &a, &b, &c) && (a != -1 || b != -1 || c != -1)) {
        memset(A, 0, sizeof(A));
        memset(fg, 0, sizeof(fg));
        cout << "w(" << a << ", " << b << ", " << c << ") = " << f(a, b, c) << endl;
    }
    return 0;
}