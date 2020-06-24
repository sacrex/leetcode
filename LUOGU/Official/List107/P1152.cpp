//
// Created by sacred on 20-6-24.
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

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N, A[1005], f[1005] = {};
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 1; i < N; ++i) {
        //n的最大值为1000,故超过1000后，[1, n-1]中一定有一个不存在的
        if (abs(A[i] - A[i-1]) > 1000) {
            cout << "Not jolly" << endl;
            return 0;
        }
        f[abs(A[i] - A[i-1])] = 1;
    }
    for (int i = 1; i < N; ++i) {
        if (!f[i]) {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}