//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

ll Exp(int n){
    if (n == 1) return 1;
    return Exp(n-1) * n;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int n;
    cin >> n;
    cout << Exp(n) << endl;

    return 0;
}