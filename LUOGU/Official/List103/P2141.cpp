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
    int N, A[105] = {0};
    map<int, int> mp;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        mp[A[i]] = 1;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (mp[A[i] + A[j]]) {
                ans++;
                mp[A[i]+A[j]] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}