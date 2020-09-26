//
// Created by sacred on 20-9-13.
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

vector<pair<string, string>> trans;
map<string, int> steps;
string A, B;

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List112/P1032.in");
#endif
    string tmpA, tmpB;
    cin >> A >> B;

    while (cin >> tmpA >> tmpB) {
        trans.push_back({tmpA, tmpB});
    }
    queue<string> q;
    q.push(A);
    steps[A] = 0;

    int ans = -1;
    while(!q.empty()) {
        string p = q.front();q.pop();

        if (p == B) {
            ans = steps[p];
            break;
        }

        for (int i = 0; i < trans.size(); ++i) {
            auto pos = p.find(trans[i].first);
            while (pos != string::npos) { //遍历串中的每一个出现的位置
               string new_str;
                if (pos == 0) {
                    new_str = trans[i].second + p.substr(trans[i].first.size());
                } else {
                    new_str = p.substr(0, pos) + trans[i].second + p.substr(pos + trans[i].first.size());
                }

                if (steps[new_str] == 0) {
                    steps[new_str] = steps[p] + 1;
                    if (steps[new_str] <= 10) {
                        q.push(new_str);
                    }
                }
                pos = p.find(trans[i].first, pos+1);
            }
        }
    }

    if (ans == -1 || ans > 10) {
        cout << "NO ANSWER!" << endl;
    } else {
        cout << ans << endl;
    }



#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}