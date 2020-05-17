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
    int n, ans = 0;
    string str;
    cin >> n >> str;

    for (int i = 0; i < str.size() - 1; ++i) {
        if (str[i] == 'V' && str[i+1] == 'K') {
            ans ++;
            str[i] = str[i+1] = '\0';
        }
    }

    for (int i = 0; i < str.size() - 1; ++i) {
        if (str[i] != '\0' && str[i+1] != '\0') {
            if (str[i] == str[i+1]) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}