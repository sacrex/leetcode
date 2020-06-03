//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

//win[A][B]，Ａ赢Ｂ的分布(1:Ａ win B; 0: A equal B; -1: A lose B)
int win[5][5] = {
        {0, -1, 1, 1, -1},
        {1, 0, -1, 1, -1},
        {-1, 1, 0, -1, 1},
        {-1, -1, 1, 0, 1},
        {1, 1, -1, -1, 0}
};


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int N, NA, NB;
    int A[205], B[205];

    cin >> N >> NA >> NB;
    for (int i = 0; i < NA; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < NB; ++i) {
        cin >> B[i];
    }

    int winA = 0, winB = 0;
    for (int i = 0; i < N; ++i) {
        if (win[A[i % NA]][B[i % NB]] == 1) winA++;
        if (win[A[i % NA]][B[i % NB]] == -1) winB++;
    }

    cout << winA << " " << winB << endl;

    return 0;
}