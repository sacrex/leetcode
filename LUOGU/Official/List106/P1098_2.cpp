//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

// pos > 0 && pos < ori.size() - 1
bool can_expand(const string& ori, int pos) {
    assert(pos > 0 && pos < ori.size() - 1);
    char l = ori[pos-1], r = ori[pos+1];

    if (isalpha(l) && isalpha(r) && r - l > 1 ||
            l >= '0' && l <= '9' && r >= '0' && r <= '9' && r - l > 1) {
        return true;
    }
    return false;
}

int p1, p2, p3;
string expand(const string& ori, int pos) {
    string ret;
    for (char i = ori[pos-1]+1; i <= ori[pos+1]-1; ++i) {
        for (int j = 1; j <= p2; ++j) {
            if (p1 == 1) ret += tolower(i);
            if (p1 == 2) ret += toupper(i);
            if (p1 == 3) ret += '*';
        }
    }
    if (p3 == 2) reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    string ori, ret;

    cin >> p1 >> p2 >> p3;
    cin >> ori;

    int pos = 0; // '-'的位置
    int prev = -1; //保存上一个'-'的位置
    while(pos < ori.size()) {
        pos = ori.find('-', pos);
        if (pos >= ori.size()) break;

        //判断pos是否为０或着 ori.size() - 1,这两种情况下，要么左边没有符号，要么右边没有符号
        if (pos == 0) {
            ret += '-';
            prev = pos;
            pos++;
            continue;
        } else if (pos == ori.size() - 1) {
            if (pos-1-prev > 0) {
                ret += ori.substr(prev+1, pos-1-prev);
            }
            ret += '-';
            prev = pos;
            break;
        }

        if (pos-1-prev > 0)
            ret += ori.substr(prev+1, pos-1-prev); //ret += [prev+1, pos-1]

        if (!can_expand(ori, pos)) {
            //如果是后继，不能输出'-'
            if (ori[pos+1] != ori[pos-1] + 1)
                ret += '-';
        } else {
            string e = expand(ori, pos); // '-'被扩展为ｅ
            ret += e;
        }

        prev = pos;
        pos++;
    }

    //此时prev一定指向ori最后一个'-',将ori中最后一个'-'之后的字符串拼接到ret
    if (ori.size() - 1 - prev > 0)
        ret += ori.substr(prev+1);
    cout << ret;

    return 0;
}