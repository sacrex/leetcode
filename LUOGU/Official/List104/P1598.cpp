//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)
#define FREOUT(x) freopen(x, "w", stdout)

inline void REDIRECT() {
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List104/P1598.in");
    FREOUT("/home/sacred/leetcode/LUOGU/Official/List104/P1598.out");
#endif
}

int main(int argc, char **argv)
{
    REDIRECT();

    map<char, int> mp;
    string str;
    int Max = -1;

    while(getline(cin, str)) {
        for (int i = 0; i < str.size(); ++i)
            if (isalpha(str[i])) {
                mp[str[i]]++;
                Max = max(Max, mp[str[i]]);
            }
    }

    for (int i = 0; i < Max; ++i) {
        int nextStarPos = -1;

        for (int j = 0; j < 51; ++j) {

            for (int k = j+1; k < 51; k++) {
                if (k % 2 == 0 && i + mp[char(k / 2 + 'A')] >= Max) {
                    nextStarPos = k;
                    break;
                }
            }
            if (j > nextStarPos) break;

            if (j % 2) printf(" ");
            else {
                char alpha = j / 2 + 'A';
                if (i + mp[alpha] >= Max) printf("*"); else printf(" ");
            }
        }
        printf("\n");
    }

    printf("A");
    for (int i = 1; i < 26; ++i) {
        printf(" %c", 'A'+i);
    }
    printf("\n");
    return 0;
}