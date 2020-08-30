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

    int L, N, K;

    cin >> L >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int l = 1, r = L;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        int start_pos = 0;
        int cnt = 0;
        for (int i = 2; i <= N; ++i) {
            while (A[i] - start_pos > mid) {
                cnt++;
                start_pos += mid;
            }
            start_pos = A[i];
        }

        if (cnt <= K) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;


#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}