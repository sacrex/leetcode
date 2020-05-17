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
    int n, t;
    cin >> n;

    int cnt = 0, zero = 1;
    while(1) {
        if(!(cin >> t)) break;

        for (int i = 0; i < t; ++i) {
            if (cnt && cnt % n == 0) printf("\n");
            if (zero) printf("0");
            else printf("1");
            cnt++;
        }
        zero ^= 1;
    }


    return 0;
}