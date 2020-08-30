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

int A[100005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    int N, M;
    cin >> N >> M;
    ll sum = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    ll l = 0, r = sum;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;

        int cnt = 0, i = 1;
        ll segment_sum = 0;

        bool ok = true;
        while (i <= N) {
            if (A[i] > mid) {
                ok = false;
                break;
            }

            if (segment_sum + A[i] < mid) {
                segment_sum += A[i];
                if (i == N) cnt++; //cnt用于记录段的个数，故需要对i==N进行特例判断
                i++;
            } else if (segment_sum + A[i] == mid) {
                segment_sum = 0;
                cnt ++;
                i++;
            } else {
                segment_sum = 0;
                cnt ++;
            }
        }

        if (!ok) {
            l = mid + 1;
        } else {
            if (cnt <= M) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << ans << endl;


#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}