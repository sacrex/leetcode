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
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n - i; j++) {
            printf("%02d", ++cnt);
        }
        printf("\n");
    }

    return 0;
}