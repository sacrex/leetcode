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

    long ans = 1;
    for (int i = n; i > 1; --i) {
        ans = (ans + 1 ) * 2;
    }
    cout << ans << endl;

    return 0;
}