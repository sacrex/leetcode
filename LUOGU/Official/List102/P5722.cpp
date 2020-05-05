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
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        sum += i;
    
    cout << sum << endl;
    
    return 0;
}