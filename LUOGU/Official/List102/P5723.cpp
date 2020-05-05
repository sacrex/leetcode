//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

bool isPrime(int x)
{
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
    int S, s = 0, cnt = 0;
    cin >> S;
    for (int i = 2; ; i++) {
        if (isPrime(i)) {
            s += i;
            if (s <= S) {
                cout << i << endl;
                cnt++;
            } else {
                break;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}