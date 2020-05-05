//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char **argv)
{
    int a, b, c;
    
    cin >> a >> b >> c;
    
    int Min = min(a, min(b, c));
    int Max = max(a, max(b, c));
    
    cout << Min / gcd(Max, Min) << "/" << Max / gcd(Max, Min) << endl;
    
    return 0;
}