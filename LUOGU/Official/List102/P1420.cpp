//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int A[10005];

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    
    int ans = 1, Max = 0;
    for (int i = 1; i < n; ++i) {
        if (A[i] == A[i-1] + 1) {
            ans++;
        } else {
            Max = max(Max, ans);
            ans = 1;
        }
    }
    cout << Max << endl;
    return 0;
}