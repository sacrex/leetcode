//
// Created by sacred on 20-7-19.
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

void dfs(int n) {
    if (n == 1) {
        cout << "2";
    } else if (n == 0) {
        cout << "0";
    } else {
        int first = 1;
        for (int i = log2(n)+1; i >= 0; --i) {
            if (n & ( 1 << i)) {
                if (first == 1) {
                    first = 0;
                } else {
                    cout << "+";
                }

                if (i != 1) cout << "2(";
                dfs(i);
                if (i != 1) cout << ")";
            }
        }
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int n;
    cin >> n;

    int first = 1;
    for (int i = 31; i >= 0; --i) {
        if (n & (1 << i)) {
            if (first) {
                first = 0;
            } else {
                cout << "+";
            }

            if (i != 1) cout << "2(";
            dfs(i);
            if (i != 1) cout << ")";
        }
    }
    cout << endl;

    return 0;
}