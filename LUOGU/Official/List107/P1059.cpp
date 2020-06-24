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

    int A[105], N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A, A+N);
    int len = unique(A, A+N) - A;

    cout << len << endl;
    for (int i = 0; i < len; ++i)
        cout << A[i] << " ";

    return 0;
}