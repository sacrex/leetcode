//
// Created by sacred on 20-6-25.
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

int A[25], f[25] = {0};
int n, r;

void dfs(int idx) {
    if (idx >= n) return;

    for (int i = 1; i >= 0; --i) { //先置1,在置0，这里很重要，后面的输出就是有序的
        f[idx] = i;
        if (idx == n-1) {
            int tot = 0;
            for (int j = 0; j < n; ++j) {
                if (f[j]) {
                    tot++;
                }
            }
            if (tot == r) {
                for (int j = 0; j < n; ++j) {
                    if (f[j]) {
                        printf("%3d", A[j]);
                    }
                }
                printf("\n");
            }
        }
        dfs(idx+1);
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    cin >> n >> r;
    if (r == 0) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        A[i] = i+1;
    }

    dfs(0);

    return 0;
}