//
// Created by sacred on 20-10-3.
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

bool match[105];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    string str;
    cin >> str;
    if (str.empty()) {
        cout << endl;
        return 0;
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            for (int j = i-1 ; j >= 0; j--) {
                if ((str[j] == '(' || str[j] == '[') && !match[j]) {
                    if (str[j] == '(') {
                        match[j] = match[i] = true;
                    }
                    break;
                }
            }
        } else if (str[i] == ']') {
            for (int j = i-1; j >= 0; j--) {
                if ((str[j] == '[' || str[j] == '(') && !match[j]) {
                    if (str[j] == '[') match[j] = match[i] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[') {
            printf("%c", str[i]);
            if (!match[i]) {
                printf("%c", str[i] == '(' ? ')' : ']');
            }
        } else {
            if (!match[i]) {
                printf("%c", str[i] == ')' ? '(' : '[');
            }
            printf("%c", str[i]);
        }
    }

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}