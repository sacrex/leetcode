//
// Created by sacred on 20-7-27.
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

struct Ratio {
    int m, v;
    bool operator<(const Ratio& o) const {
        assert(m != 0 && o.m != 0);
//        return v / m > o.v / o.m; //不行，因为m和v都是整数！！！，定义为double就可以了
        return v * o.m > m * o.v;
    }
};

struct Ratio A[105];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N, T;
    cin >> N >> T;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i].m >> A[i].v;
    }
    sort(A+1, A+N+1);

    int SumM = 0, i = 1;
    double SumV = 0.0;
    while (i <= N && SumM + A[i].m <= T) {
        SumM += A[i].m;
        SumV += A[i].v;
        i++;
    }

    if (i <= N) {
        SumV += (A[i].v * 1.0 / A[i].m) * (T - SumM);
    }
    printf("%.2f\n", SumV);

    return 0;
}