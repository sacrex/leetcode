//
// Created by sacred on 20-9-7.
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

double f[20][1<<15], x[20], y[20];

double dis(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    memset(f, 127, sizeof(f));

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int s = 1; s <= (1 << n) - 1; ++s) {
        for (int i = 1; i <= n; ++i) {

            if (s & (1 << (i-1)) == 0) continue; //i不属于s,继续

            if (s == (1 << (i-1))) { //i属于s,且s中只有i,令f[i][s]=0
                f[i][s] = 0;
                continue;
            }

            //从s中找到一个不等于i的j（j属于s，但 j != i）,做dp
            for (int j = 1; j <= n; ++j) {
                if ((s & (1 << (j-1))) == 0 || j == i) continue;

                f[i][s] = min(f[i][s], f[j][s - (1 << (i-1))] + dis(i, j));
            }
        }
    }

    double ans = -1;
    for (int i = 1; i <= n; ++i) {
        double s = f[i][(1<<n)-1] + dis(i, 0);
        if (fabs(ans+1) < 1e-6 || ans > s) ans = s;
    }
    printf("%.2lf\n", ans);

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}