//
// Created by sacred on 20-8-13.
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
typedef int CNT;

int A[200005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List111/P1102.in");
#endif
    map<int, CNT> mp;

    int N, C;
    cin >> N >> C;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A+1, A+N+1);

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (A[i] + C > A[N]) {
            break;
        }
        ll cnt = mp[A[i]+C];
        if (cnt > 0) {
            ans += mp[A[i]] * cnt;
            i += (mp[A[i]] - 1);
        }
    }
    cout << ans << endl;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}