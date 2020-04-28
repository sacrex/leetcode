//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 0x80000000;

int main(int argc, char **argv)
{
    int Md = 1; //最大值出现的日期
    int Max = inf;
    for (int i = 1; i <= 7; ++i) {
        int a, b;
        cin >> a >> b;
        if (a + b > Max) {
            Max = a + b;
            Md = i;
        }
    }
    if (Max <= 8) {
        cout << 0 << endl;
    } else {
        cout << Md << endl;
    }

    return 0;
}