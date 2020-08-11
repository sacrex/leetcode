//
// Created by sacred on 20-7-28.
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

    int N, tmp;
    cin >> N;

    priority_queue<int, vector<int>, std::greater<int> > pq;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while(pq.size() > 1) {
        int t1 = pq.top();pq.pop();
        int t2 = pq.top();pq.pop();
        ans += (t1 + t2);
        pq.push(t1+t2);
    }
    cout << ans << endl;

    return 0;
}