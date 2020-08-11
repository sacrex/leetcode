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

int A[305];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A, A+n, greater<int>());
    int i = 0, j = n - 1;
    ll ans = 0;
    ans += A[i] * A[i];
    while(i < j) {
        ans += (A[i] - A[j]) * (A[i] - A[j]);
        i++;
        if (j <= i) break;
        ans += (A[j] - A[i]) * (A[j] - A[i]);
        j--;
    }
    cout << ans << endl;

    return 0;
}