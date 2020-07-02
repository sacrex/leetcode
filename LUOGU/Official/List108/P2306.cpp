//
// Created by sacred on 20-7-2.
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
    int N;
    cin >> N;

    int S[20], B[20];
    for (int i = 1; i <= N; ++i)
        cin >> S[i] >> B[i];

    int ans = INT_MAX;
    for (int i = 1; i < (1 << N); ++i) { //枚举1...2^N

        int totS = 1, totB = 0;
        int tmp = i, k = 1;
        while(tmp) {
            if (tmp & 1) {
                totS *= S[k];
                totB += B[k];
            }
            k++;
            tmp >>= 1;
        }
        ans = min(ans, abs(totS - totB));
    }

    cout << ans << endl;

    return 0;
}