//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[100005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    vector<string> names;
    string name;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> name;
        names.push_back(name);
    }
    int op, cnt, place = 0;
    for(int i = 0; i < m; ++i) {
        cin >> op >> cnt;
        if (A[place] == 0) {
            if (op == 0) {
                place = (place - cnt + n) % n;
            } else {
                place = (place + cnt) % n;
            }
        } else {
            if (op == 0) {
                place = (place + cnt) % n;
            } else {
                place = (place - cnt + n) % n;
            }
        }
    }
    cout << names[place] << endl;

    return 0;
}