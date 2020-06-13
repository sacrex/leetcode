//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int n;
    cin >> n;
    for (int i = n; i >= 0; --i) {
        int t;
        cin >> t;
        if (!t) continue;

        //符号
        if (i != n || t < 0) {
            cout << (t > 0 ? "+" : "-");
        }

        //系数
        if (i == 0 || abs(t) != 1) {
            cout << abs(t);
        }

        //"x"
        if (i != 0) cout << "x";

        //指数
        if (i != 0 && i != 1) cout << "^" << i;
    }
    return 0;
}