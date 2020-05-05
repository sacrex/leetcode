//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int A[15];

int main(int argc, char **argv)
{
    int left = 0, LEFT = 0;

    for (int i = 1; i <= 12; ++i) {
        cin >> A[i];
        left += 300 - A[i];
        if (left < 0) {
            cout << -i << endl;
            return 0;
        } else {
            if (left >= 100) {
                int t = (left / 100) * 100;
                LEFT += t;
                left -= t;
            }
        }
    }
    cout << left + LEFT * 1.2 << endl;

    return 0;
}