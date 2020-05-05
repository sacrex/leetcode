//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

struct {
    int l, r, w;
}tree[100007 << 4];

void build(int l, int r, int root_idx)
{
    tree[root_idx].l = l, tree[root_idx].r = r;
    if (l == r){
        tree[root_idx].w = 1;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, root_idx * 2);
    build(m+1, r, root_idx * 2 + 1);
    tree[root_idx].w = tree[root_idx * 2].w + tree[root_idx * 2 + 1].w;
}

//这里的update没有使用惰性标记,直接递归到叶子节点.
void update(int root_idx, int x, int y)
{
    //到达叶子节点
    if (tree[root_idx].l == tree[root_idx].r) {
        if (x <= tree[root_idx].l && y >= tree[root_idx].l)
            tree[root_idx].w = 0;
        return;
    }
    int m = (tree[root_idx].l + tree[root_idx].r) / 2;
    if (x <= m && y >= tree[root_idx].l) { //[x,y]和左区间有交集，递归左区间
        update(root_idx * 2, max(x, tree[root_idx].l), min(m, y));
    }
    if (y >= m+1 && x <= tree[root_idx].r) { //[x,y]和右区间有交集,递归右区间
        update(root_idx * 2 + 1, max(x, m+1), min(tree[root_idx].r, y));
    }
    tree[root_idx].w = tree[root_idx * 2].w + tree[root_idx*2 + 1].w;
}


int main(){
    //FREOPEN("/home/sacred/leetcode/LUOGU/Official/List103/P1047_1.in");

    int l, m, u, v;
    cin >> l >> m;
    build(1, l+1, 1);
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        update(1, u+1, v+1);
    }
    cout << tree[1].w << endl;
}



/*
 *  暴力解法
 *
int A[10005];
int main(int argc, char **argv)
{
    int u, v, l, m;
    cin >> l >> m;
    memset(A, 0x3f, sizeof(A));

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        for (int j = u; j <= v; ++j) {
            A[j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i <= l; ++i) {
        if (A[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
*/
