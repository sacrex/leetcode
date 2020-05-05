//
// Created by sacred on 20-4-19.
//

/**
 *  数位dp
 *  求某一个数在某个数位（个位/十位／百位／...）上出现的次数
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int A[20], x, dp[20][2][2], sum[20];

int dfs(int pos, bool leadzero, bool limit)
{
    if (!pos) return 0;
    if (dp[pos][leadzero][limit] != -1) return dp[pos][leadzero][limit];

    int up = limit ? A[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; ++i) {
        ans += dfs(pos-1, leadzero && i == 0, limit && i == A[pos]);
        if (i == x) {
            //if x == 0 && 存在前导0就不用计数了
            //这个if是对前导0的判断
            if (x != 0 || !leadzero) { //对x != 0 和　x == 0 分开讨论 (2种情况: x != 0 或　(x== 0 && leadzero == 0), 才进行计数)

                if (limit && i == A[pos]) //这个if是对数位的上界判断
                    ans += sum[pos - 1] + 1;
                else
                    ans += (int)pow(10, pos - 1);
            }
        }
    }

    dp[pos][leadzero][limit] = ans;
    return ans;
}

int solve(int n)
{
    int pos = 0;
    while(n) {
        A[++pos] = n % 10;
        n /= 10;
    }
    for (int i = 1; i <= pos; ++i) {
        sum[i] = A[i] * (int)pow(10, i -1) + sum[i-1];
    }

    return dfs(pos, true, true);
}


int main(int argc, char **argv)
{
    int n;
    cin >> n >> x;

    memset(dp, -1, sizeof(dp));
    cout << solve(n) << endl;

    return 0;
}