//
// Created by sacred on 20-8-24.
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
//    time_t start_time = time(NULL);
#endif

    double l = 0.0, r = 5.0;
    int N, M, K;
    cin >> N >> M >> K;
    while (l <= r) {
        double mid = (l + r) / 2;

        double sum = 0.0;
        for (int i = 1; i <= K; ++i) {
            sum += M * 1.0 / pow(1+mid, i);
        }

        if (sum > N) {
            l = mid + 0.0001;
        } else {
            r = mid - 0.0001;
        }
    }
    printf("%.1f\n", l * 100);

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}