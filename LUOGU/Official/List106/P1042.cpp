//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

/*
 *  注释的是输入字符串的形式，现在是输入单个字符的形式。
 *  还有利用cin >> string的形式。
 *
 * 　这道题可以对比看下各种输入对应的耗时是怎样的
 */

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List106/P1042.in");
#endif
//    ios::sync_with_stdio(false);

    vector<pair<int, int>> tw1 , ele;
//    string str;
    char str;
    int win21 = 0, lost21 = 0;
    int win11 = 0, lost11 = 0;

    while(scanf("%c", &str)) {
//        for (int i = 0; i < strlen(str); ++i) {
            if ((win21 >= 21 || lost21 >= 21) && abs(win21 - lost21) >= 2) {
                tw1.push_back({win21, lost21});
                win21 = 0, lost21 = 0;
            }
            win21 += (str == 'W');
            lost21 += (str == 'L');

            if ((win11 >= 11 || lost11 >= 11) && abs(win11 - lost11) >= 2) {
                ele.push_back({win11, lost11});
                win11 = 0, lost11 = 0;
            }
            win11 += (str == 'W');
            lost11 += (str == 'L');
//        }
        if (str == 'E') break;
    }
    tw1.push_back({win21, lost21});
    ele.push_back({win11, lost11});

    for(int i = 0; i < ele.size(); ++i) {
        printf("%d:%d\n", ele[i].first, ele[i].second);
//        cout << ele[i].first << ":" << ele[i].second << endl;
    }
    printf("\n");
//    cout << endl;
    for(int i = 0; i < tw1.size(); ++i) {
        printf("%d:%d\n", tw1[i].first, tw1[i].second);
//        cout << tw1[i].first << ":" << tw1[i].second << endl;
    }
    return 0;
}