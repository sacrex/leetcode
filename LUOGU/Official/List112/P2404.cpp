//
// Created by sacred on 20-9-11.
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

int A[1000], n;

void dfs(int v, int idx, int sum)
{
    if (sum == n) {
        for (int i = 1; i <= idx; ++i) {
            if (i != 1) printf("+");
            printf("%d", A[i]);
        }
        printf("\n");
        return;
    }

    if (sum > n) {
        return;
    }

    if (sum < n) {
        for (int i = v; i < n; ++i) {
            A[idx+1] = i;
            dfs(i, idx+1, sum+i);
        }
    }
}


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        A[1] = i;
        sum = A[1];
        dfs(i, 1, sum);
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}