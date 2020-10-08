//
// Created by sacred on 20-10-3.
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

int t, n, x, pushed[100000+5];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            pushed[i] = x;
        }

        stack<int> sk;
        int next_j = 1;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            if (sk.size() && sk.top() == x) {
                sk.pop();
                continue;
            }

            for (int j = next_j; j <= n; ++j) {
                sk.push(pushed[j]);
                if (pushed[j] == x) {
                    sk.pop();
                    next_j = j+1;
                    break;
                }
            }
        }

        if (sk.size()) {
            puts("No");
        } else {
            puts("Yes");
        }
    }



#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}