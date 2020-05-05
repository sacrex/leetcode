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
    int a[11], h, ans = 0;
    for (int i = 1; i <= 10; ++i) {
        cin >> a[i];
    }
    cin >> h;
    
    for (int i = 1; i <= 10; ++i) {
        if (h+30 >= a[i]) {
            ans ++;
        }
    }
    cout << ans << endl;
    
    return 0;
}