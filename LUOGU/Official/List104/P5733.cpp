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
    cin >> str;
    auto f = [](string &str) {
        for (auto &i : str) i = toupper(i);
    };
    f(str);

    cout << str << endl;

    return 0;
}