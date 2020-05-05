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
    int A[105], t, l =0;
    while(cin >> t && t != 0)
        A[++l] = t;
    for (int i = l; i >= 1; --i) {
        if (i != l) printf(" %d", A[i]);
        else printf("%d", A[i]);
    }
    printf("\n");
    return 0;
}