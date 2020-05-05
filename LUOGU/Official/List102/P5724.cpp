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
    int n, Max = -1, Min = 10000;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (t > Max) Max = t;
        if (t < Min) Min = t;
    }
    cout << Max - Min << endl;
    return 0;
}