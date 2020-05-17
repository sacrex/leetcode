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
    getline(cin, str);

    int ans = 0;
    for(int i = 0; i < str.size(); ++i)
        if (isspace(str[i]) || str[i] == '\r' || str[i] == '\n') {}
        else ans++;
    cout << ans << endl;

    return 0;
}