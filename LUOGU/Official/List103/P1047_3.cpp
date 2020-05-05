//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

struct Pair{
    int l, r;
    bool operator<(const Pair& rhs) const {
        return l < rhs.l;
    }
}p[105];

int main(int argc, char **argv)
{
    int l, m;
    cin >> l >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> p[i].l >> p[i].r;
    }
    sort(p + 1, p + 1 + m);

    int cnt_delete_tree = 0;
    int merge_left = p[1].l, merge_right = p[1].r;
    for (int i = 2; i <= m; ++i) {
        int left = p[i].l, right = p[i].r;
        if (left <= merge_right) {
            merge_right = max(merge_right, right);
        } else {
            cnt_delete_tree += merge_right - merge_left + 1;
            merge_left = left;
            merge_right = right;
        }
    }
    cnt_delete_tree += merge_right - merge_left + 1; //最后一个
    cout << l + 1 - cnt_delete_tree << endl;
    return 0;
}