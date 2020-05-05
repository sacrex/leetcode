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
    
    double x = 0;
    if (n > 400)
        x = (n - 400) * 0.5663 + 250 * 0.4663 + 150 * 0.4463;
    else if (n > 150)
        x = (n - 150) * 0.4663 + 150 * 0.4463;
    else 
        x = n * 0.4463;
    
    printf("%.1f\n", x);
    return 0;
}