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

    int n, m;
    cin >> n >> m;
    double Max = -1.0;

    while(n--) {
        int t;
        vector<int> a;
        for (int i = 0; i < m; ++i) {
            cin >> t;
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        double sum = 0;
        for (int i = 1; i < a.size() - 1; ++i)
            sum += a[i];
        Max = max(Max, sum / (a.size() - 2));
    }
    printf("%.2f\n", Max);
    return 0;
}