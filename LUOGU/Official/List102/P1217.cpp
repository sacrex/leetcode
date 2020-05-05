//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

//素数判断(x >= 2)
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

//构造回文数

int main(int argc, char **argv)
{
    //只有1／３／５／７位数的回文数才可能是质数（２/4/7/8位数都不可能）
    int l, r;
    cin >> l >> r;

    for (int i = l; i < min(100,r); ++i) {
        if (i == 5 || i == 7 || i == 11)
            cout << i << endl;
    }

    if (r > 100) {
        for (int i = 1; i < 10; i +=2) {
            for (int j = 0; j < 10; ++j) {
                int p = i * 100 + j * 10 + i; //3位数
                if (p >= l && p <= r) {
                    if (isPrime(p)) {
                        cout << p << endl;
                    }
                }
            }
        }
    }

    if (r > 10000) {
        for (int i = 1; i < 10; i += 2) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    int p = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
                    if (p >= l && p <= r) {
                        if (isPrime(p))
                            cout << p << endl;
                    }
                }
            }
        }
    }

    if (r > 1000000) {
        for (int i = 1; i < 10; i += 2) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    for (int t = 0; t < 10; ++t) {
                        int p = i * 1000000 + j * 100000 + k * 10000 + t * 1000 + k * 100 + j * 10 + i;
                        if (p >= l && p <= r) {
                            if (isPrime(p))
                                cout << p << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}