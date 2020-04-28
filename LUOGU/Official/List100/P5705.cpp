//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    string s;
    cin >> s;

//    reverse(s.begin(), s.end());

    for (int i = 0; i <= s.size() / 2; ++i) {
        char t = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = t;
    }

    cout << s << endl;

    return 0;
}