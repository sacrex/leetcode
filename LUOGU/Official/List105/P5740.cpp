//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    string name;
    int a, b, c, N, sum;

    cin >> N;
    cin >> name >> a >> b >> c;
    sum = a + b + c;
    for(int i = 2; i <= N; ++i) {
        string temp;
        int ta, tb, tc;
        cin >> temp >> ta >> tb >> tc;
        if (ta + tb + tc > sum) {
            sum = ta + tb + tc;
            name = temp;
            a = ta,b = tb, c = tc;
        }
    }
    cout << name << " " << a << " " << b << " " << c << endl;

    return 0;
}