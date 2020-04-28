//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    if (n % 100 == 0) {
        printf("%d\n", n % 400 == 0 ? 1 : 0);
        return 0;
    }

    printf("%d\n", n % 4 == 0 ? 1 : 0);

    return 0;
}