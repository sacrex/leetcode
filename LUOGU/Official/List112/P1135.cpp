//
// Created by sacred on 20-8-31.
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

//C[i]表示到达第i层的最小次数
int AA[205], C[205];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    int N, A, B;
    cin >> N >> A >> B;
    for (int i = 1; i <= N; ++i) {
        cin >> AA[i];
    }
    for (int i = 1; i <= N; ++i) C[i] = -1;
    C[A] = 0;

    queue<int> q;
    q.push(A);
    while(!q.empty()) {
        auto p = q.front();q.pop();

        if (p == B) {
            cout << C[p] << endl;
            return 0;
        }

        //若向高层可以走
        if (p + AA[p] <= N && C[p+AA[p]] == -1) {
            C[p+AA[p]] = C[p] + 1;
            q.push(p+AA[p]);
        }
        //若向低层可以走
        if (p - AA[p] >= 1 && C[p-AA[p]] == -1) {
            C[p-AA[p]] = C[p] + 1;
            q.push(p-AA[p]);
        }
    }

    cout << -1 << endl;
    return 0;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}