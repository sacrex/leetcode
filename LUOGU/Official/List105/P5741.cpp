//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

struct S{
    string name;
    int a, b, c;
}A[1005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    vector<pair<string, string>> ans;

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i].name >> A[i].a >> A[i].b >> A[i].c;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            if (fabs(A[i].a + A[i].b + A[i].c - A[j].a - A[j].b - A[j].c) <= 10 &&
                    fabs(A[i].a - A[j].a) <= 5 &&
                    fabs(A[i].b - A[j].b) <= 5 &&
                    fabs(A[i].c - A[j].c) <= 5) {
                ans.push_back({A[i].name, A[j].name});
            }
        }
    }
    sort(ans.begin(), ans.end(), [](const pair<string, string>& a, const pair<string, string>& b) {
       if (a.first != b.first) return a.first < b.first;
       return a.second < b.second;
    });

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    printf("\n");
    return 0;
}