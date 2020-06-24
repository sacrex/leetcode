//
// Created by sacred on 20-6-24.
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

struct S{
    int x, y, z;

    bool operator<(const S &o) const {
        return z < o.z;
    }

}s[50005];

double d(S &a, S &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s[i].x >> s[i].y >> s[i].z;
    }

    sort(s, s + N);

    double sum = 0;
    for (int i = 1; i < N; ++i) {
        sum += d(s[i], s[i-1]);
    }
    printf("%.3f\n", sum);

    return 0;
}