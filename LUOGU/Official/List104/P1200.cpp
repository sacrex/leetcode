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
    string a, b;
    cin >> a >> b;
    int asum = 1, bsum = 1;
    for (int i = 0; i < a.size(); ++i) {
        asum *= (a[i] - 'A' + 1);
        asum %= 47;
    }
    for (int i = 0; i < b.size(); ++i) {
        bsum *= (b[i] - 'A' + 1);
        bsum %= 47;
    }
    if (asum == bsum)
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;

    return 0;
}