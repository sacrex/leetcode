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

string str;
// idx 从１开始索引
//　一半一半减小
int find_idx(ll len, ll idx) {
    if (idx <= str.size()) {
        return idx;
    }

    if (idx <= len / 2) {
        return find_idx(len / 2, idx); //在前半部分
    }
    idx -= len / 2;
    return find_idx(len / 2, (idx - 1 == 0) ? len / 2 : idx - 1);  //在后半部分(idx-1==0是特殊考虑)
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    ll N, sz;

    cin >> str >> N;

    sz = str.size();
    while(sz < N) {
        sz *= 2;
    }

    int idx = find_idx(sz, N);
    cout << str[idx-1] << endl;


    return 0;
}