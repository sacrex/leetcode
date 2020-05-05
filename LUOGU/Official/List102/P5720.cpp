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
    double a;
    cin >> a;
    
    if (a >= 2) {
        cout << int(log2(a)) + 1 << endl;
    } else {
        cout << 1 << endl;
    }
    
    return 0;
}