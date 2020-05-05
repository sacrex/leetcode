//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int main(int argc, char **argv)
{
    int N;
    cin >> N;

    N /= 52 * 7;

    for (int x = N - 1; x > 0; x--) {
        if ((N - x) % 3 == 0 && x <= 100) {
            cout << x << "\n" << (N - x) / 3 << endl;
            break;
        }
    }

    return 0;
}