//
// Created by sacred on 20-7-8.
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

//[DXXXXX[DXXXX]xxx[DXXXX]]
//遇到一个'['就递归，然后往右扫描，如果再遇到[，继续递归，否则
//遇到就是],那么得出[和]之将的字符串返回。然后上一层继续找 ']'

string dfs(const string& str, int &idx) {
    if (idx >= str.size()) {
        return "";
    }

    string ori;
    int i = idx+1;
    while(i < str.size()) {
        if (str[i] == '[') {
            ori += dfs(str, i);
        } else if (str[i] == ']') {
            idx = i; //对dfs的第二个参数修改
            break;
        } else {
            ori += str[i];
        }
        i++;
    }

    //ori就是由[]所包围的，并且是展开后的串
    int D = 0, sz = ori.size(), alpha = 0;
    while(alpha < sz && isdigit(ori[alpha])) {
        D = D * 10 + (ori[alpha] - '0');
        alpha ++;
    }

    string s;
    while (alpha < sz) {
        s += ori[alpha];
        alpha ++;
    }

    string ret;
    if (D && !s.empty()) for (int i = 0; i < D; ++i) ret += s;

    return ret;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List109/P1928.in");
#endif
    string str;
    cin >> str;

    //下面这种方式就是一直补齐法（也就是让dfs一定从下标为[开始）
    if (isdigit(str[0])) {
        str = "[" + str + "]";
    } else {
        str = "[1" + str + "]"; //开头不是数字，补个１
    }

    int i = 0;
    string ret = dfs(str, i);
    cout << ret << endl;

    return 0;
}