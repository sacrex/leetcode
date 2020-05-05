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

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << n / i << endl;
            break;
        }
    }

    return 0;
}