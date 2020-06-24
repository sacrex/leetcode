//
// Created by sacred on 20-6-24.
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

struct S {
  int a, b, c;
  bool operator<(S &o) const {
      return a < o.a;
  }
};
vector<S> vec;


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int A, B, C;
    cin >> A >> B >> C;

    vector<int> Arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        int a = Arr[0] * 100 + Arr[1] * 10 + Arr[2];
        int b = Arr[3] * 100 + Arr[4] * 10 + Arr[5];
        int c = Arr[6] * 100 + Arr[7] * 10 + Arr[8];
        if (A * b == B * a && A * c == C * a && B * c == C * b) {
            S s;
            s.a = min(a, min(b, c));
            s.c = max(a, max(b, c));
            s.b = a + b + c - s.a - s.c;
            vec.push_back(s);
        }
    }while(next_permutation(Arr.begin(), Arr.end()));

    if (vec.empty()) {
        cout << "No!!!" << endl;
        return 0;
    }

    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i].a << " " << vec[i].b << " " << vec[i].c << endl;
    }

    return 0;
}