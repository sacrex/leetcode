//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    int m, t, s;
    cin >> m >> t >> s;

    int k = 0, ans;
    if (s % t)
        k = 1;

    ans = m - (s / t + k);
    if (ans < 0)
        ans = 0;

    cout << ans << endl;
    return 0;
}