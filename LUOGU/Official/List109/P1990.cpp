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

int A[1000005];
int sum[1000005]; //sum[i] = F[i] + F[i-1] + ... + F[1] + 1

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N;
    cin >> N;

    A[1] = 1;
    A[2] = 2;
    sum[0] = 1;
    sum[1] = A[1] + 1; //2
    sum[2] = A[2] + A[1] + 1; //4

    // 递推式(分以下情况):
    //  0    00   001  110  0011 0110  00110  01100
    //  0    11   011  100  0221 0000  01100  00110  .....(还有无数)
    //  N-1  N-2  N-3  N-3   N-4  N-4   N-5    N-5   ....
    //　从上面看出 N-3, N-4, N-5,...N-(N-1)都存在两种情况，而N-1,N-2只有１种情况.
    // 最后剩余的１也有２种情况，可以分析当N=3时，F[4] = F[２] + F[１] + 2 * (1)
    // F[N] = F[N-1] + F[N-2] + 2 * (F[N-3] + F[N-4] + ... + F[1] + 1)

    //利用sum[i] = F[i] + F[i-1] + F[i-2] + ... + F[1] + 1　来优化
    for (int i = 3; i <= N; ++i) {
        int k = (A[i-1] + A[i-2]) % 10000;
        k = (k + (2 * sum[i-3]) % 10000) % 10000;
        A[i] = k;
        sum[i] = (sum[i-1] + A[i]) % 10000;
    }

    cout << A[N] << endl;

    return 0;
}