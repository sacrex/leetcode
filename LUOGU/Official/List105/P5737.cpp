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

    int x, y;
    vector<int> v;
    cin >> x >> y;
    for(int i = x; i <= y; ++i) {
        if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0) {
            v.push_back(i);
        }
    }

    cout << v.size() << endl;
    if (v.empty()) return 0;
    for (int i = 0; i < v.size(); ++i) {
        if (!i) printf("%d", v[i]);
        else printf(" %d", v[i]);
    }

    return 0;
}