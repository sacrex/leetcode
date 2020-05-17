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
            {'a', 0},
            {'b', 0},
            {'c', 0}
    };

    string text, temp;
    cin >> text;
    stringstream ss(text);
    while(getline(ss, temp, ';')) {
       if (isdigit(temp[3])) {
           mp[temp[0]] = temp[3] - '0';
       } else {
           mp[temp[0]] = mp[temp[3]];
       }
    }
    cout << mp['a'] << " " << mp['b'] << " " << mp['c'] << endl;
    return 0;
}