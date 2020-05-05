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
    if (N  == 0 ) {
        cout << 0 << endl;
        return 0;
    }

    if (N < 0) {
        cout << '-';
        N = -N;
    }
    int first = 0;
    while(N) {
        if (N % 10) {
            first = 1;
            cout << N % 10;
        } else {
            if (first) cout << 0;
        }

        N /= 10;
    }
    cout << endl;

    return 0;
}