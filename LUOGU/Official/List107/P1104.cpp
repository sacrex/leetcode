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

struct S {
    string name;
    int id, y, m, d;

    bool operator<(const S &o) const {
        if (y != o.y) return y < o.y;
        if (m != o.m) return m < o.m;
        if (d != o.d) return d < o.d;
        return id > o.id;
    }

}s[100];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        s[i].id = i+1;
        cin >> s[i].name >> s[i].y >> s[i].m >> s[i].d;
    }

    sort(s, s + N);

    for (int i = 0; i < N; ++i) {
        cout << s[i].name <<endl;
    }


    return 0;
}