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
    int n, ans[10] = {0};
    map<int, int> win;
    cin >> n;
    for (int i = 0; i < 7; ++i){
        int t;
        cin >> t;
        win[t] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = 0; j < 7; ++j) {
            int t;
            cin >> t;
            if (win[t]) cnt++;
        }
        ans[7-cnt]++;
    }

    for (int i = 0; i < 7; ++i) {
        if (i) printf(" %d", ans[i]);
        else printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}