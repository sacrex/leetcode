//
// Created by sacred on 20-8-15.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//buf数组缓存数组（预读到buf数组）
char Buf[1 << 16], *p = Buf, *q = Buf;
#define Getchar() (p == q && (q = (p = Buf) + fread(Buf, 1, 1 << 16, stdin), p == q) ? EOF : *p++)
inline int Read() {
    char ch = Getchar();
    int x = 0,f = 1;
    while (ch < '0'|| ch > '9') {
        if(ch=='-')
            f=-1;
        ch = Getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x=10 * x + ch - '0';
        ch = Getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

double f(double a, double b, double c, double d, double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

void get_ans(double a, double b, double c, double d, double l, double r, vector<double>& ans)
{
    double t = f(a, b, c, d, l), k = f(a, b, c, d, r);
    if (fabs(t) <= 1e-5 && fabs(k) <= 1e-5) {
        ans.push_back(l);
        return;
    }

    if (r - l < 1 && t * k > 0) {
        return;
    }

    double mid = (l + r) / 2;
    get_ans(a, b, c, d, l, mid, ans);
    get_ans(a, b, c, d, mid, r, ans);
    return;
}


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<double> ans;

    double l = -100, r = 100;
    get_ans(a, b, c, d, l, 0, ans);
    get_ans(a, b, c, d, 0, r, ans);

    for(int i = 0; i < ans.size(); ++i) {
        printf("%.2f ", ans[i]);
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}