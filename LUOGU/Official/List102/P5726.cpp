//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

double A[1006];

int main(int argc, char **argv)
{
    int n, Max = -1, Min = 11;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] > Max) Max = A[i];
        if (A[i] < Min) Min = A[i];
        sum += A[i];
    }
    sum -= Max;
    sum -= Min;

    printf("%.2f\n", sum / (n - 2));

    return 0;
}