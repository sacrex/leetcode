//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    double m, h;
    cin >> m >> h;
    
    double K = m / (h * h);
    
    if (K < 18.5) {
        cout << "Underweight" << endl;
    } else if ((K >18.5 || fabs(K - 18.5) <= 10e-8) && K < 24) {
        cout << "Normal";
    } else {
        cout << K << "\n" << "Overweight" << endl;
    }
    
    return 0;
}