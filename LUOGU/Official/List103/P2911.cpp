//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[100] = {0};

int main(int argc, char **argv)
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <= s2; ++j) {
            for (int k = 1; k <= s3; ++k) {
                A[i+j+k]++;
            }
        }
    }
    int Max = A[1], ans = 0;
    for (int i = 2; i < 100; ++i) {
        if (A[i] > Max) {
            ans = i;
            Max = A[i];
        }
    }
    cout << ans << endl;
    return 0;
}