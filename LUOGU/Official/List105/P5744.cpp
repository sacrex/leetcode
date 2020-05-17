//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int n;
    cin >> n;
    string name;
    int age, grade;
    for (int i = 0; i < n; ++i) {
        cin >> name >> age >> grade;
        grade *= 1.2;
        if (grade >= 600) grade = 600;
        cout << name << " " << age + 1 << " " << grade << endl;
    }
    
    return 0;
}