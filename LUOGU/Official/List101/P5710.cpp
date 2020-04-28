//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    int x;
    cin >> x;

    int A = x % 2 == 0;
    int B = x > 4 && x <= 12;

    printf("%d ", A && B ? 1 : 0);
    printf("%d ", A || B ? 1 : 0);
    printf("%d ", ((!A && B) || (A && !B)) ? 1 : 0);
    printf("%d\n", (!A && !B) ? 1 : 0);

    return 0;
}