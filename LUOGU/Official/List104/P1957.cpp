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
    int n;
    cin >> n;

    char op;
    int a, b;
    string tmp;
    while(n--){
        cin >> tmp;
        if (isdigit(tmp[0])) {
            a = atoi(tmp.c_str());
            cin >> b;
        } else {
            op = tmp[0];
            cin >> a >> b;
        }

        int r;
        if (op == 'a') {
            r = fprintf(stdout, "%d+%d=%d", a, b, a+b);
        } else if (op == 'b') {
            r = fprintf(stdout, "%d-%d=%d", a, b, a-b);
        } else if (op == 'c') {
            r = fprintf(stdout, "%d*%d=%d", a, b, a*b);
        }
        cout << endl;
        cout << r << endl;
    }

    return 0;
}