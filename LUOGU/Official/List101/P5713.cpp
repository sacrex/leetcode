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
    
    printf("%s\n", (n * 5 <= 11 + n * 3) ? "Local" : "Luogu");
    
    return 0;
}