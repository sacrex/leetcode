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
    int n, a, p1, b, p2, c, p3;
    cin >> n >> a >> p1 >> b >> p2 >> c >> p3;

    int Min = -1;

    if (n < a) {
        Min = p1;
    } else if (n % a == 0) {
        Min = (n / a) * p1;
    } else {
        Min = (n / a + 1) * p1;
    }

    if (n < b) {
        Min = min(Min, p2);
    } else if (n % b == 0) {
        Min = min(Min, (n / b) * p2);
    } else {
        Min = min(Min, (n / b + 1) * p2);
    }

    if (n < c) {
        Min = min(Min, p3);
    } else if (n % c == 0) {
        Min = min(Min, n / c * p3);
    } else {
        Min = min(Min, (n / c + 1) * p3);
    }

    cout << Min << endl;

    return 0;
}