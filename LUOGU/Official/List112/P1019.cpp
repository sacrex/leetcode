//
// Created by sacred on 20-9-8.
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

int n;
map<string, int> mp;
vector<string> strs;
int ans = 0;

//只需求最小重叠部分,返回重叠的长度
int Union(string s, string t)
{
    if (s.size() > t.size()) {
        for (int i = 1; i < t.size(); ++i) {
            if (s.substr(s.size() - i) == t.substr(0, i)) return i;
        }

    } else {
        for (int i = 1; i < s.size(); ++i) {
            if (s.substr(s.size() - i) == t.substr(0, i)) return i;
        }
    }

    return 0;
}

void dfs(int t, int &len)
{
    string s = strs[t];

    vector<int> v;
    for (int i = 0; i < strs.size(); ++i) {
        if (Union(s, strs[i])) {
            v.push_back(i);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (mp[strs[v[i]]] >= 2) continue;
        len += strs[v[i]].size();
        int t = Union(s, strs[v[i]]);
        len -= t;
        mp[strs[v[i]]]++;

        dfs(v[i], len);

        mp[strs[v[i]]]--; //回溯
        len += t;
        len -= strs[v[i]].size();
    }

    if (len > ans) ans = len;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    char c;
    cin >> c;
    int len = 0;
    for (int i = 0; i < strs.size(); ++i) {
        if (strs[i][0] == c) {
            mp[strs[i]]++;
            len = strs[i].size();
            dfs(i, len);
            mp[strs[i]]--;
        }
    }

    printf("%d\n", ans);

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}