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
    int n;
    cin >> n;

    if (n == 0)
        cout << 0 << ".00" << endl;
    else if (n ==1 || n == 2)
        cout << 1 << ".00" << endl;
    else {
        ll a = 1, b = 1, c;
        for (int i = 3; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        cout << c << ".00" << endl;
    }

    return 0;
}