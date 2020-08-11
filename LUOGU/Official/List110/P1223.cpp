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

struct T {
    int idx, t;
    bool operator<(const T& o) const {
        return t < o.t;
    }
};
T A[1005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        A[i].idx = i;
        cin >> A[i].t;
    }
    sort(A+1, A+N+1);

    cout << A[1].idx;
    for (int i = 2; i <= N; ++i)
        cout << " " << A[i].idx;
    cout << endl;

    ll sum = 0, Sum = 0;
    for (int i = 2; i <= N; ++i) {
        sum += A[i-1].t;
        Sum += sum;
    }

    printf("%.2lf\n", Sum * 1.0 / N);

    return 0;
}