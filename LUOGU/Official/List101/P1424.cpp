//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int main(int argc, char **argv)
{
    int x, n;
    cin >> x >> n;

    int ans = (n / 7) * 250 * 5;
    if (n % 7 != 0) {
        for (int i = x; i < x + n % 7; ++i) {
            int k = i;
            if (k > 7) k -= 7;
            if (k != 6 && k != 7) {
                ans += 250;
            }

        }
    }
    cout << ans << endl;

    return 0;
}