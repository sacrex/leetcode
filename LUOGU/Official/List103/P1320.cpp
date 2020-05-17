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
    string str, tmp;
    cin >> str;
    int n = str.size();

    printf("%d", n);

    for (int i = 2; i <= n; ++i) {
        cin >> tmp;
        str += tmp;
    }

    int i = 0, cnt = 0;
    while(i < str.size()) {
        while(str[i] == '0') {
            cnt++;
            i++;
        }
        printf(" %d", cnt);
        cnt = 0;

        if (i >= str.size()) break;
        while(str[i] == '1') {
            cnt++;
            i++;
        }
        printf(" %d", cnt);
        cnt=0;
    }
    printf("\n");
    return 0;
}