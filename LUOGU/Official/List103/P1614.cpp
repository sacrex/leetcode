//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[4000];

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    int sum = 0, Min = 0x3f3f3f3f;

    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        sum += A[i];
        if (i == n) {
            Min = min(Min, sum);
            break;
        }
        if (i >= m) {
            Min = min(Min, sum);
            sum -= A[i-m+1];
        }
    }
    cout << Min << endl;
    return 0;
}