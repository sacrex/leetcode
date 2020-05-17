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
    map<string, int> mp = {
            {"one", 1},
            {"a", 1},
            {"both", 2},
            {"another", 1},
            {"first", 1},
            {"second", 2},
            {"third", 3},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
            {"seven", 7},
            {"eight", 8},
            {"nine", 9},
            {"ten", 10},
            {"eleven", 11},
            {"twelve", 12},
            {"thirteen", 13},
            {"fourteen", 14},
            {"fifteen", 15},
            {"sixteen", 16},
            {"seventeen", 17},
            {"eighteen", 18},
            {"nineteen", 19},
            {"twenty", 20},
    };

    string str, temp;
    getline(cin, str);
    vector<int> vec;
    stringstream ss(str);
    while(ss >> temp) {
        if (temp[temp.size()-1] == '.') temp = temp.substr(0, temp.size() - 1);
        if (mp[temp]) {
            vec.push_back(mp[temp] * mp[temp] % 100); //这里可以优化，是０的话可以不存,那么后面输出可以简单点
        }
    }
    sort(vec.begin(), vec.end());

    char A[30] = {0}, *p = A;
    int t = 0;
    for(int i = 0; i < vec.size(); ++i) {
        t = sprintf(p, "%02d", vec[i]);
        p += t;
    }

    t = 0;
    while(A[t] == '0') t++;
    if (A[t] == '\0') printf("0\n");
    else printf("%s\n", A+t);

    return 0;
}