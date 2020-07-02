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

//int main(int argc, char **argv)
//{
//#ifndef ONLINE_JUDGE
//#endif
//    int n;
//    cin >> n;
//
//    int A[10];
//    for (int i = 0; i < n; ++i) {
//        A[i] = i+1;
//    }
//
//    do {
//        for (int i = 0; i < n; ++i) {
//            printf("%5d", A[i]);
//        }
//        printf("\n");
//    }while(next_permutation(A, A+n));
//
//    return 0;
//}


int A[10], f[10] = {0};
int n;
void dfs(int idx) {
    if (idx > n) return;

    for (int i = 1; i <= n; ++i) {

        if (f[i]) {
            continue;
        }
        //走到这一步，这个ｉ就是未使用的

        A[idx] = i;
        f[i] = 1;

        if (idx == n) {
            for (int j = 1; j <= n; ++j) {
                printf("%5d", A[j]);
            }
            printf("\n");
        }

        dfs(idx+1);
        f[i] = 0; //这里不要忘了！！！！！！
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    cin >> n;

    dfs(1); //从idx=1开始吧！！，也可以从０开始，随意

    return 0;
}