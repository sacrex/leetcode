//
// Created by sacred on 20-8-16.
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

int M[100005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> M[i];
    }
    sort(M+1, M+m+1);

    int N, ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> N;
        int *low = lower_bound(M+1, M+m+1, N);
        if (low == M+m+1) {
            ans += fabs(M[m] - N);
        } else if (low == M+1) {
            ans += fabs(M[1] - N);
        } else {
            ans += min(fabs(low[-1] - N), fabs(low[0] - N));
        }
    }
    cout << ans << endl;


#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}