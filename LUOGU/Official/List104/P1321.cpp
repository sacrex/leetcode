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
    string str;
    int boy = 0, girl = 0;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'b' || (i+1 < str.size() && str[i+1] == 'o') || (i+2 < str.size() && str[i+2] == 'y'))
            boy++;
        if (str[i] == 'g' || (i+1 < str.size() && str[i+1] == 'i') || (i+2 < str.size() && str[i+2] == 'r')
                || (i+3 < str.size() && str[i+3] == 'l'))
            girl++;
    }
    cout << boy << endl << girl << endl;

    return 0;
}