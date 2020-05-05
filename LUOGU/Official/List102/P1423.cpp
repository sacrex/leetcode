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
    double x, sum = 2, t = 2.0;
    cin >> x;
    
    if (x <= 2.0) {
        cout << 1 << endl;
        return 0;
    }
    
    for (int i = 2; ; i++) {
        t *= 0.98;
        sum += t;
        if (sum >= x) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}