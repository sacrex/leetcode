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
    string str;
    cin >> n >> str;

    int op, a, b;
    string s;
    while(n--){
        cin >> op;
        if (op == 1) {
            cin >> s;
            str += s;
            cout << str << endl;
        } else if (op == 2) {
            cin >> a >> b;
            str = str.substr(a, b);
            cout << str << endl;
        } else if (op == 3) {
            cin >> a >> s;
            str = str.substr(0, a) + s + str.substr(a);
            cout << str << endl;
        } else if (op == 4) {
            cin >> s;
            size_t i = str.find(s);
            if (i == string::npos) {
                cout << -1 << endl;
            } else {
                cout << i << endl;
            }
        }
    }
    return 0;
}