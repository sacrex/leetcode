//
// Created by sacred on 20-10-4.
//

#include <bits/stdc++.h>
using namespace std;

#define FREOPEN(x) freopen(x, "r", stdin)
typedef long long ll;
typedef unsigned long long ull;

#define BEGIN_TIMER do \
{ \
    time_t start_time = time(NULL); \
}while(0);

#define END_TIMER do \
{ \
    time_t end_time = time(NULL); \
    cout << "Cost Time(s): " << end_time - start_time << endl; \
}while(0);

const int maxn = 1e5 + 5;
struct node {
    int l, r;
    int val, key;
    int size;
}fhq[maxn];
int cnt, root;

int newnode(int val)
{
    fhq[++cnt].val = val;
    fhq[cnt].key = rand() % 1000;
    fhq[cnt].size = 1;
    return cnt;
}

void update(int id)
{
    if (!id) return;
    fhq[id].size = fhq[fhq[id].l].size + fhq[fhq[id].r].size + 1;
}

void split(int id, int val, int &x, int &y)
{
    if (id == 0) {
        x = y = 0;
        return;
    }
    if (fhq[id].val <= val) {
        x = id;
        split(fhq[id].r, val, fhq[id].r, y);
    } else {
        y = id;
        split(fhq[id].l, val, x, fhq[id].l);
    }
    update(id);
}

int merge(int x, int y)
{
    if (!x || !y) return x+y;

    //构造一个大根堆
    if (fhq[x].key >= fhq[y].key) {
        fhq[x].r = merge(fhq[x].r, y);
        update(x);
        return x;
    } else {
        fhq[y].l = merge(x, fhq[y].l);
        update(y);
        return y;
    }
}

//树的基本操作

//插入，返回新节点的编号
int insert(int val)
{
    int x, y;
    split(root, val, x, y);
    int ret = newnode(val);
    root = merge(merge(x, ret), y);
    return ret;
}

//删除，返回删除节点的编号
int del(int val)
{
    int x, y, z;
    split(root, val, x, z);
    split(x, val - 1, x, y);

    int ret = y;
    y = merge(fhq[y].l, fhq[y].r);
    root = merge(merge(x, y), z);
    return ret;
}

//查找val对应的排名
int getrank(int val)
{
    int x, y;
    split(root, val-1, x, y);
    int ret = fhq[x].size + 1;
    root = merge(x, y);
    return ret;
}

//获取排名为rank的元素
int getnum(int rank)
{
    int id = root;
    while(id) {
        if (fhq[fhq[id].l].size + 1 == rank) {
            break;
        }
        if (fhq[fhq[id].l].size + 1 > rank) {
            id = fhq[id].l;
        } else {
            rank -= fhq[fhq[id].l].size + 1;
            id = fhq[id].r;
        }
    }
    return fhq[id].val;
}

int prev(int val)
{
    int x, y;
    split(root, val-1, x, y);
    int id = x;
    while(fhq[id].r) {
        id = fhq[id].r;
    }
    int ret = fhq[id].val;

    root = merge(x, y);
    return ret;
}

int next(int val)
{
    int x, y;
    split(root, val, x, y);
    int id = y;
    while(fhq[id].l) {
        id = fhq[id].l;
    }
    int ret = fhq[id].val;
    root = merge(x, y);
    return ret;
}

int main(int argc, char **argv)
{
    FREOPEN("/home/sacred/leetcode/Advanced Alogrithm/FHQ Treap/P3369_in.txt");
    int N;
    int opt, x;
    scanf("%d", &N);
    while(N--) {
        scanf("%d%d", &opt, &x);
        switch (opt) {
            case 1:
                insert(x);
                break;
            case 2:
                del(x);
                break;
            case 3:
                printf("%d\n", getrank(x));
                break;
            case 4:
                printf("%d\n", getnum(x));
                break;
            case 5:
                printf("%d\n", prev(x));
                break;
            case 6:
                printf("%d\n", next(x));
                break;
        }
    }
    return 0;
}
