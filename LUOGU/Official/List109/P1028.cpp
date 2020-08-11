//
// Created by sacred on 20-7-5.
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

ll A[1005];

/*
 * A[i]: 表示i对应的个数
 *
 * 下面的表示方法都是反序表示
 *
 * A[1] = 1, (1)
 * A[2] = 2; (2 | 21)
 * A[3] = 3; (3 | 31)
 * A[4] = 4; (4 | 42 | 421 | 41)
 * ...
 * A[8] = 1 + A[4] + A[3] + A[2] + A[1] (8, 8后面接4(故A[4]对应的数), 8后面接３(故A[3]对应的数), 8后面接２(故A[2]对应的数)，８后面接１（故A[1]对应数）)
 *   所以可以有(8 | 84 842 8421 841 | 83 831 | 82, 821  | 81)
 *
 * 故可以直接递推得出
 */

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    A[1] = 1;
    A[2] = 2;
    A[3] = 2;

    int n;
    cin >> n;
    if (n <= 3) {
        cout << A[n] << endl;
        return 0;
    }

    for (int i = 4; i <= n; ++i) {
        for (int j = 1; j <= i/2; ++j)
            A[i] += A[j];

        A[i] += 1; //他本身
    }

    cout << A[n] << endl;

    return 0;
}