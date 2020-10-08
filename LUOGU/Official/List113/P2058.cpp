//
// Created by sacred on 20-10-3.
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

typedef pair<int, int> P; //<ti, x>
int cnt[100000+5], N, ans, t, k, x;

P que[300000+5];
int b, e;  //队头和队尾

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &t, &k);

        for (int j = 0; j < k; ++j) {
            scanf("%d", &x);

            que[e++] = P(t, x);

            if (cnt[x] == 0) {
                ans++;
            }
            cnt[x]++;
        }

        while(b < e && que[b].first <= t - 86400) {
            cnt[que[b].second]--;
            if (cnt[que[b].second] == 0) {
                ans--;
            }
            b++;
        }

        printf("%d\n", ans);
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}