//
// Created by sacred on 20-7-4.
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

ll A[20];

//递推方式
/*
 * 卡特兰数
 *
 * A[0] = 1(假设)
 * A[1] = １;
 * A[2] = ２;
 *
 *  A[n] = sum(A[j-1] * A[n-j]) (j = 1...n)
 *　例如 A[5] = A[4] + A[1] * A[3] + A[2] * A[2] + A[3] * A[1] + A[4];
 *  也就是让１（这里取１，因为１在每一个不同的位置上，就是一个解）处于每个位置上,然后计算 [１前面的空位可以排列的个数]　* [1 后面的空位可以排列的个数]
 */

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    A[1] = 1;
    A[2] = 2;

    int n;
    cin >> n;
    if (n <= 2) {
        cout << A[n] << endl;
        return 0;
    }

    for (int i = 3; i <= n; ++i) {

        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) A[i] += A[i-1];
            else {
                A[i] += A[j-1] * A[i-j];
            }
        }
    }

    cout << A[n] << endl;

    return 0;
}