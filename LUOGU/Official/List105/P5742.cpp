//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)
#define FREPUT(x) freopen(x, "w", stdout)

struct Stu {
    int a, b, n;
    double c;
    Stu(int n = 0, int a = 0, int b = 0)
            : a(a), b(b) {
        c = a * 0.7 + b * 0.3;
    }
    double get() {
        return c;
    }
};

bool excellent(struct Stu stu) {
    if (stu.a + stu.b > 140 && stu.get() >= 80)
        return true;
    return false;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List105/P5742.in");
    FREPUT("/home/sacred/leetcode/LUOGU/Official/List105/P5742.out");
#endif
    int N;
    cin >> N;
    int a, b, n;
    for (int i = 0; i < N; ++i) {
        cin >> n >> a >> b;
        Stu s(n, a, b);
        if (excellent(s))
            cout << "Excellent" << endl;
        else
            cout << "Not excellent" << endl;
    }

    return 0;
}