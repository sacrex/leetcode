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

    int n;
    cin >> n;
    int t, first = 1;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (isPrime(t)) {
            if(first) {
                printf("%d", t); 
                first =0;
            } else {
                printf(" %d", t);
            }
        }
    }

    return 0;
}