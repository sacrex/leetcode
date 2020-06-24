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

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    vector<pair<int, string>> A;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        A.push_back({i+1, tmp});
    }

    sort(A.begin(), A.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.second.size() != b.second.size()) return a.second.size() > b.second.size();
        return a.second > b.second;
    });

    cout << A[0].first << endl;
    cout << A[0].second << endl;


    return 0;
}