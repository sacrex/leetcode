//Given a string s, find the longest palindromic substring in s. You may assume
//that the maximum length of s is 1000.
//
// Example 1:
//
//
//Input: "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
//Input: "cbbd"
//Output: "bb"
//
// Related Topics String Dynamic Programming

/*
 *  采用的是马拉车算法　求一个串中的最长的回文子串 O(N)
 *  https://www.cnblogs.com/grandyang/p/4475985.html
 *  Manacher's Algorithm
 */

#include <bits/stdc++.h>
using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
char d[1000 * 2 + 5];  //s[i]处理后数组
int  r[1000 * 2 + 5];  //下标i处的回文半径
int maxi = 1, maxr = 2; //当前最大的回文半径处的索引和值

class Solution {
public:
    string longestPalindrome(string s) {
        maxi = 1, maxr = 2;

        if (s.empty() || s.size() == 1)
            return s;
        for (int i = 0; i < s.size(); ++i) {
            d[2 * i] = '#';
            d[2 * i + 1] = s[i];
        }
        d[2 * s.size()] = '#';

        r[0] = 1;
        r[1] = 2;
        for(int i = 2; i < 2 * s.size() + 1; ++i) {
            //求出ｉ对于当前最大回文半径的索引的对称点
            int j = maxi * 2 - i;
            int left = maxi - (maxr - 1);//最大回文半径的索引对应的最左端点

            if (j <= left) {
                r[i] = 1;
                int li = i - r[i];
                int ri = i + r[i];
                while(li >= 0 && ri <= 2 * s.size() && d[li] == d[ri]) {
                    li--;
                    ri++;
                    r[i]++;
                }
                //更新完r[i]
            } else {
                //求出ｊ对应的最左端点
                int left_j = j - (r[j] - 1);
                if (left_j > left) {
                    r[i] = r[j];
                } else {
                    r[i] = j - left + 1; //取ｊ的串必须是在left的右边!!! 不能写成r[i] = r[j].
                    //继续从 i + r[i]处比对下去
                    int ri = i + r[i];
                    int li = i - r[i];
                    while(li >= 0 && ri <= 2 * s.size() && d[li] == d[ri]) {
                        r[i]++;
                        li--;
                        ri++;
                    }
                    //更新完r[i]
                }
            }

            //更新maxr,maxi
            if (r[i] > maxr) {
                maxr = r[i];
                maxi = i;
            }

        }

        if (maxi % 2) {
            string ret = "";
            for (int k = maxi - maxr + 1; k <= maxi + maxr + 1; k += 2)
                ret += d[k];
        } else {
            string ret = "";
            for (int k = maxi - marr + 2; k <= maxi + maxr; k += 2)
                ret += d[k];
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    return 0;
}