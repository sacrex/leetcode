//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    int a, b, c;
    cin >> a >> b >> c;
    
    int Min = min(a, min(b, c));
    int Max = max(a, max(b, c));
    int Mid = a + b + c - Min - Max;
    
    cout << Min << " " << Mid << " " << Max << endl;
    
    return 0;
}