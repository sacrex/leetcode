//
// Created by sacred on 20-7-30.
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

int A[100005];
struct Range {
    int L, R;
    bool have_children;
    vector<int> min_idx;
    vector<Range*> children;
    Range(int l = 0, int r = 0) : L(l), R(r), have_children(true) {}
};

Range* createNode(int L, int R)
{
    Range * r = new Range(L, R);
    assert(r != nullptr);

    //处理特例
    if (L == R) {
        r->min_idx.push_back(L);
        r->have_children = false;
        return r;
    }

    int Min = 1000000;
    for (int i = L; i <= R; ++i) {
        if (A[i] < Min) Min = A[i];
    }
    for (int i = L; i <= R; ++i) {
        if (A[i] == Min) {
            r->min_idx.push_back(i);
        }
    }
    if (r->min_idx.size() == R - L + 1) {
        r->have_children = false;
    }

    return r;
}

Range *createTree(int L, int R)
{
    Range *root = createNode(L, R);
    if (!root->have_children) {
        return root;
    }
    if (root->min_idx.size() == R - L + 1) {
        root->min_idx.clear();
        root->min_idx.push_back(L);
        return root;
    }

    for (int i = 0; i < root->min_idx.size(); ++i) {
        int l = (i == 0) ? L : root->min_idx[i-1] + 1;
        int r = root->min_idx[i] - 1;
        if (l <= r) {
            Range *c = createTree(l, r);
            root->children.push_back(c);
        }
    }
    if (root->min_idx[root->min_idx.size() - 1] != R) {
        int l = root->min_idx[root->min_idx.size() - 1] + 1;
        int r = R;
        if (l <= r) {
            root->children.push_back(createTree(l, r));
        }
    }

    return root;
}

void printTree(Range *root, int indent = 2) {

    cout << "Range: \n";
    cout << "L: " << root->L << " R: " << root->R << endl;
    cout << "min_idx: " << root->min_idx.size() << endl;
    for (int i = 0; i < root->min_idx.size(); ++i) {
        cout << root->min_idx[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < indent; ++i) cout << "\t";
    cout << "Children: ------\n";
    for (int i = 0; i < root->children.size(); ++i) {
        printTree(root->children[i], indent + 2);
    }
    for (int i = 0; i < indent; ++i) cout << "\t";
    cout << "Children: -------\n";
}

void dfs(Range *root, Range *parent, int &ans) {
    if (!parent) {
        ans += A[root->min_idx[0]];
    } else {
        ans += A[root->min_idx[0]] - A[parent->min_idx[0]];
    }

    for (int i = 0; i < root->children.size(); ++i) {
        dfs(root->children[i], root, ans);
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    Range *root = createTree(1, N);
    int ans = 0;
    dfs(root, nullptr, ans);

    cout << ans << endl;

    return 0;
}


/*
 *  下面这种贪心的思想（差分）
 */
//int main()
//{
//    int N, l = 0, ans = 0;
//    N = Read();
//    for (int i = 1; i <= N; ++i) {
//        int t;
//        t = Read();
//        if (t > l) ans += (t - l);
//        l = t;
//    }
//    cout << ans << endl;
//}