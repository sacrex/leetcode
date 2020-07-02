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

//素数判断(x >= 0)
bool isPrime(int x)
{
    if (x == 0 || x == 1)
        return false;

    if (x == 2 || x == 3)
        return true;
    for (int i = 2; i <= int(sqrt(x)); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)


int A[20], f[20] = {0};
int n, k;

int ans = 0;
/// 对f[0...n-1]中一层一层深搜, 若只有f[0]和f[1], 且初始都为0, 则先是f[0] = 0, 在是f[1] = 0, 在是f[1] = 1, 回退到f[0] = 1,在是f[1] = 0,　最后是f[1] = 1.
void dfs(int idx) {
    if (idx >= n) return;

    for (int i = 0; i <= 1; ++i) {
        f[idx] = i;
        if (idx == n-1) { //深搜到最后一层在判断,这里最关键
            int sum = 0, tot = 0;
            for (int j = 0; j < n; ++j) {
                if (f[j]) {
                    sum += A[j];
                    tot++;
                }
            }
            if (tot == k && isPrime(sum)) ans++;
        }
        dfs(idx+1);
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}