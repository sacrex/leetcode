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

// sz表示初始大小, n表示当前需要执行的递归层数
// e.g sz = 10, n = 5, 那么表示的是 oooooxxxxx--oxoxoxoxox
void print_line(int sz, int n) {
    for (int i = 0; i < n; ++i) cout << 'o';
    for (int i = 0; i < n; ++i) cout << '*';
    cout << "--";
    for (int i = sz - n; i > 0; i--) cout << "o*";
    cout << endl;
}

void print_dfs(int sz, int n)
{
    if (n == 4) {
        print_line(sz, n);
        cout << "ooo--***o*"; for (int i = sz - n; i > 0; --i) cout << "o*"; cout << endl;
        cout << "ooo*o**--*"; for (int i = sz - n; i > 0; --i) cout << "o*"; cout << endl;
        cout << "o--*o**oo*"; for (int i = sz - n; i > 0; --i) cout << "o*"; cout << endl;
        cout << "o*o*o*--o*"; for (int i = sz - n; i > 0; --i) cout << "o*"; cout << endl;
        cout << "--o*o*o*o*"; for (int i = sz - n; i > 0; --i) cout << "o*"; cout << endl;
        return ;
    }

    //oooooxxxxx--
    print_line(sz, n);

    //oooo--xxxxox
    for (int i = 0; i < n-1; ++i) cout << 'o';
    cout << "--";
    for (int i = 0; i < n-1; ++i) cout << '*';
    for (int i = sz - n + 1; i > 0; --i) cout << "o*";
    cout << endl;

    print_dfs(sz, n - 1);
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int n;
    cin >> n;

    print_dfs(n, n);

    return 0;
}