//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

//素数判断(x >= 0)
bool isPrime(int x)
{
    if (x == 0 || x == 1)
        return false;

    if (x == 2 || x == 3)
        return true;
    for (int i = 2; i <= int(sqrt(x)); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    map<int, int> prime;
    for (int i = 2; i <= 10000; ++i) {
        if (isPrime(i)) prime[i] = 1;
    }

    int N;
    cin >> N;
    for (int i = 4; i <= N; i += 2) {
        for (int j = 2; j <= i / 2; ++j) {
            if (prime[j] && prime[i-j]) {
                cout << i << "=" << j << "+" << i-j << endl;
                break;
            }
        }
    }

    return 0;
}