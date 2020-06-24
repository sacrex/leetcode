//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

//int A[2000005];
int B[1000];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < m; ++i) {
//        cin >> A[i];
//    }
//    sort(A, A+m);
//    for (int i = 0; i < m; ++i) {
//        if (i) cout << " ";
//        cout << A[i];
//    }
//    cout << endl;

    int n, m, tmp;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        B[tmp]++;
    }
    int first = 1;
    for (int i = 1; i < 1000; ++i) {
        for (int j = 0; j < B[i]; ++j) {
            if (!first) cout << " ";
            else {
                first = 0;
            }
            cout << i;
        }
    }
    cout << endl;

    return 0;
}