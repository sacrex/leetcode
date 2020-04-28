//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    int a, b, c, d, e, f, total_minute;
    cin >> a >> b >> c >> d;

    total_minute = (c - a) * 60 + d - b;
    e = total_minute / 60;
    f = total_minute % 60;
    
    cout << e << " " << f << endl;

    return 0;
}