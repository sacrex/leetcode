//
// Created by sacred on 20-10-4.
//

#include <bits/stdc++.h>
using namespace std;

#define FREOPEN(x) freopen(x, "r", stdin)
typedef long long ll;
typedef unsigned long long ull;

#define BEGIN_TIMER time_t start_time = time(NULL);

#define END_TIMER do \
{ \
    time_t end_time = time(NULL); \
    cout << "Cost Time(s): " << end_time - start_time << endl; \
}while(0);

struct node {
    int l, r;
    int val;
    int size;
    int key; //排名，堆
}fhq[33000];
int cnt, root;

int newnode(int val)
{
    fhq[++cnt].val = val;
    fhq[cnt].size = 1;
    fhq[cnt].key = rand() % 1000;
    return cnt;
}

void update(int id)
{
    if (!id) return ;
    fhq[id].size = fhq[fhq[id].l].size + fhq[fhq[id].r].size;
}

void split(int id, int val, int &x, int &y)
{
    if (id == 0) {
        x = y = 0;
        return ;
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
    if (!x || !y) return x + y;
    if (fhq[x].key <= fhq[y].key) {
        fhq[x].r = merge(fhq[x].r, y);
        update(x);
        return x;
    } else {
        fhq[y].l = merge(x, fhq[y].l);
        update(y);
        return y;
    }
}

void insert(int val)
{
    int x, y;
    split(root, val-1, x, y);
    root = merge(merge(x, newnode(val)), y);
}

// 返回<val的最大值的rank
int prev(int val)
{
    int x, y;
    split(root, val-1, x, y);
    int now = x;
    while (fhq[now].r) {
        now = fhq[now].r;
    }
    root = merge(x, y);
    return now;
}

// 返回>val的最小值的rank
int next(int val)
{
    int x, y;
    split(root, val, x, y);
    int now = y;
    while (fhq[now].l) {
        now = fhq[now].l;
    }
    root = merge(x, y);
    return now;
}

bool exist(int root, int val)
{
    if (!root) return false;
    if(fhq[root].val == val) return true;
    else if (fhq[root].val < val) return exist(fhq[root].r, val);
    else return exist(fhq[root].l, val);
}

int main(int argc, char **argv)
{
    int N, val, ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &val);
        if (i == 0) {
            ans += val;
            insert(val);
        }
        else {
            int p, n, minX = 0x3fffffff;
            if (!exist(root, val)) {
                p = prev(val);
                if (p) {
                    minX = min(minX, abs(fhq[p].val - val));
                }
                n = next(val);
                if (n) {
                    minX = min(minX, abs(fhq[n].val - val));
                }
                ans += minX;
            }
            insert(val);
        }
    }

    printf("%d\n", ans);
    return 0;
}