//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

//pos_num表示职位等级，３为护法，４为长老,...
struct People{
    string name, pos;
    int pos_num, num, level, id;
    People(const string &name = "", const string& pos = "", int pos_num = 0, int num = 0, int level = 0, int id = 0):
            name(name), pos(pos), pos_num(pos_num), num(num), level(level), id(id){}
};

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    vector<People> p1, p2;
    int N;
    cin >> N;
    People p;
    for (int i = 1; i <= N; ++i) {
        p.id = i;
        cin >> p.name >> p.pos >> p.num >> p.level;
        if (p.pos == "BangZhu" || p.pos == "FuBangZhu") {
            if (p.pos == "BangZhu") p.pos_num = 1;
            else p.pos_num = 2;
            p1.push_back(p);
        } else {
            if (p.pos == "HuFa") p.pos_num = 3;
            else if (p.pos == "ZhangLao") p.pos_num = 4;
            else if (p.pos == "TangZhu") p.pos_num = 5;
            else if (p.pos == "JingYing") p.pos_num = 6;
            else p.pos_num = 7;
            p2.push_back(p);
        }
    }
    //按帮贡从大到小排序,帮贡相同时，按id排序
    sort(p2.begin(), p2.end(), [](const People& a, const People &b) {
        if (a.num != b.num) return a.num > b.num;
        return a.id < b.id;
    });

    int huFa = 0, zhangLao = 0, tangZhu = 0, jingYing = 0;
    for (int i = 0; i < p2.size(); ++i) {
        if (huFa < 2) {
            p2[i].pos = "HuFa";
            p2[i].pos_num = 3;
            huFa++;
        } else if (zhangLao < 4) {
            p2[i].pos = "ZhangLao";
            p2[i].pos_num = 4;
            zhangLao++;
        } else if (tangZhu < 7) {
            p2[i].pos = "TangZhu";
            p2[i].pos_num = 5;
            tangZhu++;
        } else if (jingYing < 25) {
            p2[i].pos = "JingYing";
            p2[i].pos_num = 6;
            jingYing++;
        } else {
            p2[i].pos = "BangZhong";
            p2[i].pos_num = 7;
        }
    }

    //按职位排序，再按等级排序，再按id排序
    sort(p2.begin(), p2.end(), [](const People& a, const People& b) {
        if (a.pos_num != b.pos_num) return a.pos_num < b.pos_num;
        if (a.level != b.level) return a.level > b.level;
        return a.id < b.id;
    });

    //先按职位排序,再按id排序(或则没有id排序也可以)
    sort(p1.begin(), p1.end(), [](const People& a, const People& b) {
        if (a.pos_num != b.pos_num) return a.pos_num < b.pos_num;
        return a.id < b.id;
    });
    for(int i = 0; i < p1.size(); ++i) {
        cout << p1[i].name << " " << p1[i].pos << " " << p1[i].level << endl;
    }
    for(int i = 0; i < p2.size(); ++i) {
        cout << p2[i].name << " " << p2[i].pos << " " << p2[i].level << endl;
    }

    return 0;
}