//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    printf("%.1f\n", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}