//
// Created by sacred on 20-4-19.
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
    int id, a, b, c;

    bool operator<(const S &o) const {
        if (a+b+c != o.a + o.b + o.c) return a+b+c > o.a+o.b+o.c;
        if (a != o.a) return a > o.a;
        return id < o.id;
    }
}s[305];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        s[i].id = i+1;
        cin >> s[i].a >> s[i].b >> s[i].c;
    }

    sort(s, s+N);

    for (int i = 0; i < 5; ++i)
        cout << s[i].id << " " << s[i].a + s[i].b + s[i].c << endl;

    return 0;
}