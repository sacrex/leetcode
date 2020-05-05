//
// Created by sacred on 20-4-19.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//typedef unsigned long long ull;
//
//const int inf = 0x80000000;

/*
 *  计数问题
 *
 *  暴力算法:
 *
 *  朴素算法: 求ｘ在每一位上出现的次数，然后求和即可。
 *  例如n = 11, x = 1, 当模拟的1在个位上时，出现２次，即01, 11(只看个位).
 *  当模拟的1出现在十位上时,出现2次,即10, 11(只看十位).故1总共出现4次.
 * 　
 *  数位dp:
 *
 */

/*
int main(int argc, char **argv)
{
    int n, x;
    cin >> n >> x;

    int l = 0, N = n, a[10];
    while(N) {
        a[l++] = N % 10;
        N /= 10;
    }

    int ans = 0;
    for (int i = 0; i < l; ++i) {
        int left = n / (int)pow(10, i+1);
        int right = n % (int)pow(10, i);

        if (x < a[i]) {
            if (x == 0) { //对０特殊考虑
                //当模拟０到达最高位时，不做处理
                if (i != l - 1) ans += (left - 1) * (int)pow(10, i) + right + 1;
            } else {
                ans += (left + 1) * (int)pow(10, i);
            }
        } else if (x == a[i]) {
            if (x == 0) {
                ans += (left - 1) * (int)pow(10, i);
            } else {
                ans += left * (int)pow(10, i);
            }
            ans += right + 1;
        } else {
            ans += left * (int)pow(10, i);
        }
    }

    cout << ans << endl;

    return 0;
}
*/


//数位dp的解法

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x,y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define MAXN 15
#define MAXM 15
#define fi first
#define se second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 1 << 30;
const int p = 10000007;
int lowbit(int x){ return x & -x; }
int fast_power(int a, int b){ int x; for(x = 1; b; b >>= 1){ if(b & 1) x = 1ll * x * a % p; a = 1ll * a * a % p; } return x; }
//head by DYH

int m;
int power[MAXM], num[MAXM], sum[MAXM], dp[MAXN][2][2];

int dfs(int pos, bool zero, bool limit){
    if(!pos) return 0;
    int& res = dp[pos][zero][limit];
    if(res != -1) return res;
    res = 0;
    int up = limit ? num[pos] : 9;
    rep(i, 0, up){
        bool nlimit = limit && i == up, nzero = zero && !i;
        res += dfs(pos - 1, nzero, nlimit);
        if(i == m && !(zero && !m)){
            if(limit && i == up) res += sum[pos - 1] + 1;
            else res += power[pos];
        }
    }
    return res;
}

int solve(int x){
    int len = 0;
    clr(dp, -1);
    while(x){
        num[++len] = x % 10;
        x /= 10;
    }
    rep(i, 1, len) sum[i] = num[i] * power[i] + sum[i - 1];
    return dfs(len, 1, 1);
}

int main(){
    int n;
    scanf("%d%d", &n, &m);
    power[1] = 1;
    rep(i, 2, 8) power[i] = power[i - 1] * 10;
    printf("%d\n", solve(n));
    return 0;
}


