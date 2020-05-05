//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

long long A[100000];

int main(int argc, char **argv)
{
    long long n, l = 0;
    cin >> n;
    A[++l] = n;
    while(n != 1) {
        if (n % 2) {
            n = n * 3 + 1;
            A[++l] = n;
        } else {
            n >>= 1;
            A[++l] = n;
        }
    }
    for (int i = l; i >= 1; --i) {
        if (i != l) printf(" %d", A[i]);
        else printf("%d", A[i]);
    }
    printf("\n");
    return 0;
}