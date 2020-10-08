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

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif
    string s;
    cin >> s;
    int i = 0;
    while (i < s.size() && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) i++;

    stack<int> st;
    for (;i < s.size();) {
        if (isdigit(s[i])) {
            int num = 0;
            while(s[i] != '.') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            st.push(num);
        } else if (s[i] == '-') {
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push(b - a);
        } else if (s[i] == '+') {
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push(a + b);
        } else if (s[i] == '*') {
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push(a * b);
        } else if (s[i] == '/') {
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            st.push(b / a);
        } else if (s[i] == '@') {
            break;
        }
        i++;
    }
    cout << st.top() << endl;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}