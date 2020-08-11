//
// Created by sacred on 20-7-30.
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

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    string in;
    int n, idx = 0, lenA = 1;
    char A[255];

    cin >> in >> n;
    n = in.size() - n;

    A[0] = in[0];
    //以下循环就是对in[i]找到一个合适的位置
    for (int i = 1; i < in.size(); i++) {
        int r = in.size() - i;
        idx = (n - r) < 0 ? 0 : n - r;
        int j;
        for (j = idx; j < lenA; ++j) {
            if (A[j] > in[i]) {
                A[j] = in[i];
                lenA = j+1;
                break;
            }
        }
        if (j == lenA) {
            A[j] = in[i];
            lenA = j+1;
        }
    }
    int flag = 0;
    for (int i = 0; i < n; ++i) if (A[i] != '0') {flag = 1;break;}

    if (flag == 0) {
        cout << '0' << endl;
        return 0;
    }

    int i = 0;
    while(i < n && A[i] == '0') i++;
    for (; i < n; ++i) cout << A[i];
    cout << endl;

    return 0;
}