//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[1005][3];

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int N = n;
    while(n) {
        cin >> A[n][0] >> A[n][1] >> A[n][2];
        n--;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (abs(A[i][0] - A[j][0]) <= 5 &&
            abs(A[i][1] - A[j][1]) <= 5 &&
            abs(A[i][2] - A[j][2]) <= 5 &&
            abs(A[i][0] + A[i][1] + A[i][2] - A[j][0] - A[j][1] - A[j][2]) <= 10)
                ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}