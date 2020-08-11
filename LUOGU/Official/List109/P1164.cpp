//
// Created by sacred on 20-7-9.
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

// F[M][i]: 从第i, i+1, ..., N中，取出的数的和等于Ｍ的种数(也就是01背包)
// 递归方程: F[M][i] = F[M-a[i]][i+1] + F[M][i+1]
//                        取a[i]         不取a[i]
int F[10005][105], A[105], flag[10005][105];
int N;
int f(int M, int i) {
    if (M == 0) return 1;
    if (i >= N) return 0;

    if (flag[M][i]) {
        return F[M][i];
    }

    int r = 0;
    if (M - A[i] >= 0)
        r += f(M - A[i], i+1);
    r += f(M, i+1);

    flag[M][i] = 1;
    F[M][i] = r;

    return r;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> A[i];

    cout << f(M, 0) << endl;

    return 0;
}