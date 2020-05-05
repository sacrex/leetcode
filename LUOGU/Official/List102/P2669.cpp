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
    int K, k, sum = 0;
    cin >> K;
    
    k = int(sqrt(2 * K + 0.25) - 0.5);
    sum += k * (k + 1) * (2 * k + 1) / 6;
    
    sum += (K - (1 + k) * k / 2) * (k+1);
    
    cout << sum << endl;
    
    return 0;
}