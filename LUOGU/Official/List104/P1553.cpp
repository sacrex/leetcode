//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

bool allZero(string s)
{
    for (int i = 0; i < s.size(); ++i)
        if (s[i] != '0') return false;
    return true;
}

//decimal 小数部分
void printReverse(string s, bool decimal = false)
{
    if (allZero(s)) {
        printf("0");
    } else {
        if (!decimal) {
            //正常的整数
            int i = s.size() - 1;
            while (s[i] == '0') i--;
            for (int j = i; j >= 0; --j) printf("%c", s[j]);
        }
        else {
            //小数部分
            int i = 0, j = s.size() -1;
            while(s[i] == '0') i++;
            while(s[j] == '0') j--;
            for (int k = j; k >= i; k--) printf("%c", s[k]);
        }
    }
}

int main(int argc, char **argv)
{
    string str;
    cin >> str;

    if (str.find('.') != string::npos) {
        size_t idx = str.find('.');
        printReverse(str.substr(0, idx));
        printf(".");
        printReverse(str.substr(idx+1), true); //小数部分
    } else if (str.find('/') != string::npos) {
        size_t idx = str.find('/');
        printReverse(str.substr(0, idx));
        printf("/");
        printReverse(str.substr(idx+1));
    } else if (str.find('%') != string::npos) {
        size_t idx = str.size() - 1;
        printReverse(str.substr(0, idx));
        printf("%%");
    } else {
        printReverse(str);
    }
    cout << endl;
    return 0;
}