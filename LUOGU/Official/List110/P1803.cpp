//
// Created by sacred on 20-7-28.
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

struct Line {
    int a, b;
    bool operator<(const Line& o) const {
        if (a != o.a) return a < o.a;
        return b - a <= o.b - o.a;
    }
};

Line A[1000005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a >> A[i].b;
    }
    sort(A, A+N); //按左端点从小到大排序，并且在左端点相等时，长度较小的排在前面

    int ans = 1;
    int l = A[0].a, r = A[0].b;
    //两两比较，并对ans修改
    for (int i = 1; i < N; ++i) {
        if (A[i].a >= r) {
            ans++;
            l = A[i].a;
            r = A[i].b;
        } else if (A[i].b > r) {
            //nothing to do
        } else {
            l = A[i].a;
            r = A[i].b;
        }
    }
    cout << ans << endl;

    return 0;
}