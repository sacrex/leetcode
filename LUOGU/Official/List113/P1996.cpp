//
// Created by sacred on 20-9-26.
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

struct Node {
    int idx;
    struct Node *next;
    Node(int idx = 0) : idx(idx), next(nullptr){}
};

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    int n, m;
    cin >> n >> m;

    struct Node *start = nullptr, *cur = nullptr;
    for (int i = 1; i <= n; ++i) {
        struct Node *p = new Node(i);
        if (start == nullptr) {
            start = cur = p;
        } else {
            cur->next = p;
            cur = p;
        }
    }
    cur->next = start;

    cur = start;
    while(cur->next != cur) {
        struct Node *del = cur, *prev = nullptr;
        for (int i = 0; i < m - 1; ++i) {
            prev = del;
            del = del->next;
        }
        cout << del->idx << " ";
        prev->next = del->next;
        delete del;
        cur = prev->next;
    }
    cout << cur->idx << endl;
    delete cur;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}