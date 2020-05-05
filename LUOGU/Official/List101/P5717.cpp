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
    int a, b, c;
    cin >> a >> b >> c;

    int Min = min(a, min(b, c));
    int Max = max(a, max(b, c));
    int Mid = a + b + c - Min - Max;

    if (Min + Mid <= Max) {
        cout << "Not triangle" << endl;
    } else {
        if ( Min * Min + Mid * Mid == Max * Max)
            cout << "Right triangle" << endl;
        else if (Min * Min + Mid * Mid > Max * Max)
            cout << "Acute triangle" << endl;
        else
            cout << "Obtuse triangle" << endl;


        if (a == b || a == c || b == c) {
            cout << "Isosceles triangle" << endl;
        }
        if (a == b  && a == c) {
            cout << "Equilateral triangle" << endl;
        }
    }

    return 0;
}