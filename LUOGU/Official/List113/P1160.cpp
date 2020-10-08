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
    struct Node *prev, *next;
    Node(int idx = 0):idx(idx),prev(nullptr),next(nullptr){}
};

map<int, struct Node *> mp;

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    int n;
    cin >> n;
    struct Node *node = new Node(1);
    mp[1] = node;

    int k, p;
    for (int i = 2; i <= n; ++i) {
        struct Node *newNode = new Node(i);
        mp[i] = newNode;

        cin >> k >> p;
        struct Node *cur = mp[k];
        if (p) {
            newNode->prev = cur;
            newNode->next = cur->next;
            if (cur->next) cur->next->prev = newNode;
            cur->next = newNode;
        } else {
            newNode->next = cur;
            newNode->prev = cur->prev;
            if (cur->prev) cur->prev->next = newNode;
            cur->prev = newNode;
        }
    }

    int M, x;
    cin >> M;
    while (M--) {
        cin >> x;
        if (mp[x]) {
            if (mp[x]->prev) mp[x]->prev->next = mp[x]->next;
            if (mp[x]->next) mp[x]->next->prev = mp[x]->prev;
            delete mp[x];
            mp[x] = nullptr;
        }
    }

    struct Node *b = nullptr;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second) {
            b = it->second;
            break;
        }
    }

    while(b->prev) {
        b = b->prev;
    }

    while(b) {
        cout << b->idx << " ";
        b = b->next;
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}