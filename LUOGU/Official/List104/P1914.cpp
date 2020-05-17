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
    int n;
    string ori;
    cin >> n >> ori;

    n %= 26;
    for (int i = 0; i < ori.size(); ++i) {
        ori[i] = (char)(((int)ori[i] + n - (int)'a') % 26 + 'a');
    }
    cout << ori << endl;

    return 0;
}