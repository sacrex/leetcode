//
// Created by sacred on 20-6-27.
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

// digit -> matches(火柴数)
map<int, int> mp = {
        {0, 6},
        {1, 2},
        {2, 5},
        {3, 5},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 3},
        {8, 7},
        {9, 6}
};

// 采用mpArr 比起 mp 快了30倍!!!
int mpArr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int Match(int i) {
    if (i < 10) return mpArr[i];
    int ans = 0;
    while (i > 0) {
        ans += mpArr[i % 10];
        i /= 10;
    }
    return ans;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int n, ans = 0;
    cin >> n;

    n -= 4;
    for (int i = 0; i < 1000; ++i) {
        for (int j = i; j < 1000; ++j) {
            int cntA = Match(i);
//            if (cntA >= n) continue;
            int cntB = Match(j);
//            if (cntA + cntB >= n) continue;
            int cntC = Match(i + j);
            if (cntA + cntB + cntC == n) {
                ans++;
                if (i != j) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

/*

int testMatchMap(int i) {
    if (i < 10) return mp[i];
    int ans = 0;
    while (i > 0) {
        ans += mp[i % 10];
        i /= 10;
    }
    return ans;
}

int testMapAndArray() {

    clock_t t1 = clock();
    for (int i = 1; i < 100000000; ++i) {
        int a = Match(i);
    }
    clock_t t2 = clock();

    cout << "array: " << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;

    t1 = clock();
    for (int i = 1; i < 100000000; ++i) {
        int a = testMatchMap(i);
    }
    t2 = clock();

    cout << "map: " << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;

}

int main() {
    testMapAndArray();
    return 0;
}

*/