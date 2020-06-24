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

vector<string> res;
int A[20] = {}, n;

void dfs(int idx, int tot) {
    if (idx > 10) return;

    for (int g = 1; g <= 3; ++g) {
        A[idx] = g;
        tot += g;
        if (idx == 10 && tot == n) {
            res.push_back("");
            for (int i = 1; i <= 10; ++i) {
                res.back() += to_string(A[i]);
            }
        }
        dfs(idx+1, tot);
        tot -= g; //这一步不要忘了
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    cin >> n;
    if (n < 10 || n > 30) {
        cout << 0 << endl;
        return 0;
    }

    int tot = 0;
    dfs(1, tot);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}