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

int A[1000005], n, m;

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    std::ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
       cin >> A[i];
    }

    for (int i = 1; i <= m; ++i) {
        cin >> q;

        int l = 1, r = n, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] == q) {
                ans = mid;
                r = mid - 1;
            } else if (A[mid] > q) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << " ";
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}