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
    string s;
    cin >> s;
    int X = 0, idx = 1;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (isdigit(s[i])) {
            X += (s[i] - '0') * (idx++);
        }
    }
    X %= 11;

    if ((X == 10 && s[s.size() - 1] == 'X') || X == s[s.size() - 1] - '0') {
        cout << "Right" << endl;
    } else {
        if (X == 10)
            s[s.size()-1] = 'X';
        else
            s[s.size()-1] = (char)(X + '0');
        cout << s << endl;
    }

    return 0;
}