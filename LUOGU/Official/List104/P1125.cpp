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
    string str;
    int A[256] = {0};

    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        A[str[i]]++;

    int Max = -1, Min = 1000;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (!A[i]) continue;
        Max = max(Max, A[i]);
        Min = min(Min, A[i]);
    }
    if (isPrime(Max - Min)) {
        cout << "Lucky Word" << "\n" << Max - Min << "\n";
    } else {
        cout << "No Answer" << "\n" << 0 << "\n";
    }

    return 0;
}