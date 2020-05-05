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
    bool lazy;
}tree[100007 << 2];

//root_idx从１开始　（后序遍历）
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

void down_to_child(int root_idx)
{
    tree[root_idx*2].w = 0;
    tree[root_idx*2+1].w = 0;
    tree[root_idx*2].lazy = tree[root_idx].lazy;
    tree[root_idx*2+1].lazy = tree[root_idx].lazy;
    tree[root_idx].lazy = false;
}

void update(int root_idx, int x, int y)
{
    if (x <= tree[root_idx].l && y >= tree[root_idx].r) {
        tree[root_idx].w = 0;
        tree[root_idx].lazy = true; //若满足[x,y]包含root_idx对应的区间,就对这个节点进行惰性标记,此时不需要继续递遍历其子节点了.
        return;
    }
    if (tree[root_idx].lazy)
        down_to_child(root_idx); //把惰性标记迁移至其左右孩子节点.因为下面会对其左右孩子进行递归.
    int m = (tree[root_idx].l + tree[root_idx].r) / 2;
    if (x <= m) update(root_idx * 2, x, y);
    if (y >= m+1) update(root_idx * 2 + 1, x, y);
    tree[root_idx].w = tree[root_idx*2].w + tree[root_idx*2+1].w;
}


int main(){
    //FREOPEN("/home/sacred/leetcode/LUOGU/Official/List103/P1047_1.in");

    int l, m, u, v;
    cin >> l >> m;

    memset(tree, 0, sizeof(tree));

    build(1, l+1, 1); //构造树的区间从[0,l]　改为 [1, l+1],这样root就在tree[1],而不是tree[0],符合线段树的构造过程
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        update(1, u+1, v+1);
    }
    cout << tree[1].w << endl;
}