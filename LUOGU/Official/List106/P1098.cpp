//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    string ori, ret;
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3 >> ori;
    int pos = 0, begin = 0;
    while(pos < ori.size()) {
        pos = ori.find('-', pos);
        if (pos == string::npos) break;

        int l = pos-1, r = pos+1;
        ret += ori.substr(begin, l - begin+1);

        if (pos == 0) {
            ret += "-";
            begin = pos = r;
            continue;
        } else if (pos == ori.size() - 1) {
            begin = pos;
            break;
        }

        pos = r;

        //执行替换
        string v;
        if (ori[l] >= ori[r]) {
            v = "-";
        } else if (ori[l]+1 == ori[r]) {
            //nothing to do
        }  else {
            if (isalpha(ori[l]) && isalpha(ori[r]) || (ori[l] >= '0' && ori[l] <= '9' && ori[r] >= '0' && ori[r] <= '9')) {

                for(char i = ori[l]+1; i < ori[r]; ++i) {
                    for (int j = 0; j < p2; ++j) {
                        if (p1 == 3) v += '*';
                        else if (p1 == 1) {
                            v += tolower(i);
                        } else {
                            v += toupper(i);
                        }
                    }
                }
                if (p3 == 2) std::reverse(v.begin(), v.end());
            } else {
                v = "-";
            }
        }
        ret += v;
        begin = r;
    }
    ret += ori.substr(begin);
    cout << ret;
    return 0;
}