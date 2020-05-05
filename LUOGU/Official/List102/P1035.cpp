//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
const int MAX = 0x7fffffff;

//其他方法: 调和级数求和


int main(int argc, char **argv)
{
    int k;
    cin >> k;

    double sum = 0.0;
    for (int i = 1; i < MAX; ++i) {
        sum += 1.0 * 1 / i;
        if (sum > k) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}