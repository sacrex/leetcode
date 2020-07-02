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

int A[4][25], dp[605];

int f(int idx, int cnt) {
    int tot = 0;
    for (int i = 0; i < cnt; ++i) tot += A[idx][i];

    /*
     * 因为左右脑的工作量需要越接近越好, 故以tot/2作为背包容量，那么只要其中一边尽可能接近
     * tot/2，就能保证两边的差值最小
     *
     * 01背包
     * 背包大小为tot/2, 物品个数为cnt个，每个物品的价值为A[idx][i]
     *
     */
    for (int i = 0; i < cnt; ++i) {
        //p表示背包容量
        for (int p = tot/2; p >= A[idx][i]; p--) {
            dp[p] = max(dp[p], dp[p-A[idx][i]] + A[idx][i]);
        }
    }
    int ret = tot - dp[tot/2];
    memset(dp, 0, sizeof(dp));
    return ret;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for (int i = 0; i < s[0]; ++i) cin >> A[0][i];
    for (int i = 0; i < s[1]; ++i) cin >> A[1][i];
    for (int i = 0; i < s[2]; ++i) cin >> A[2][i];
    for (int i = 0; i < s[3]; ++i) cin >> A[3][i];

    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += f(i, s[i]);
    }

    cout << ans << endl;

    return 0;
}