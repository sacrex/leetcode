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
    map<char, int> mp = {
            {'a', 1},
            {'b', 2},
            {'c', 3},
            {'d', 1},
            {'e', 2},
            {'f', 3},
            {'g', 1},
            {'h', 2},
            {'i', 3},
            {'j', 1},
            {'k', 2},
            {'l', 3},
            {'m', 1},
            {'n', 2},
            {'o', 3},
            {'p', 1},
            {'q', 2},
            {'r', 3},
            {'s', 4},
            {'t', 1},
            {'u', 2},
            {'v', 3},
            {'w', 1},
            {'x', 2},
            {'y', 3},
            {'z', 4},
            {' ', 1}
    };
    
    string str;
    getline(cin, str);
    
    int ans = 0;
    for (int i = 0; i < str.size(); ++i) {
        ans += mp[str[i]];
    }
    
    cout << ans << endl;
    return 0;
}