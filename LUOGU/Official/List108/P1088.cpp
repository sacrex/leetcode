//
// Created by sacred on 20-6-25.
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
        if(ch == '-') f = -1;
        ch = Getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = 10 * x + ch - '0';
        ch = Getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[10005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List108/P1088.in");
#endif

    int N, M;
    N = Read();
    M = Read();
    for (int i = 0; i < N; ++i) {
        A[i] = Read();
    }

    for (int i = 0; i < M; ++i) {
        next_permutation(A, A + N);
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", A[i]);
    }

    return 0;
}