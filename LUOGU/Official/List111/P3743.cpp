//
// Created by sacred on 20-8-29.
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

int Ai[100005], Bi[100005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    ll n, p;
    cin >> n >> p;
    ll sum_Ai = 0;

    double min_time = 0, max_time = 10000000000;
    for (int i = 1; i <= n; ++i) {
        cin >> Ai[i] >> Bi[i];
        sum_Ai += Ai[i];
    }

    if (p >= sum_Ai) {
        cout << -1 << endl;
        return 0;
    }

    while (min_time <= max_time) {
        double mid = (min_time + max_time) / 2;

        /*
         * 这里是按时间来算的
         *
        double need_time = 0;
        for (int i = 1; i <= n; ++i) {
            double t = 1.0 * Bi[i] / Ai[i];
            if (t < mid) {
                need_time += (mid * Ai[i] - Bi[i]) / p;
            }
        }
        if (need_time > mid) {
            max_time = mid - 1e-3;
        } else {
            min_time = mid + 1e-3;
        }
        */

        //这里是按能量使用来算，与按时间使用来算其实是一样的。
        double need_power = 0;
        for (int i = 1; i <= n; ++i) {
            if (Ai[i] * mid > Bi[i]) {
                need_power += (Ai[i] * mid - Bi[i]);
            }
        }
        if (need_power <= p * mid) {
            min_time = mid + 1e-4;
        } else {
            max_time = mid - 1e-4;
        }

    }

    cout << min_time << endl;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}