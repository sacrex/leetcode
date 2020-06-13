//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

map<int, int> mach_available_time[25]; //每台机器的可用时间，初始为[0, INT_MAX)

map<int, pair<int, int>> oper_exec; //记录操作的执行区间 [开始时刻, 结束时刻)

int mach[25][25]; //j-k操作所在的机器
int TM[25][25]; //j-k操作的耗时
int n, m;

int getId(int J, int K) {
    return J * 100 + K;
}

//获取J-K操作在所在机器能执行的最早时刻,且必须在after_this_time(也就是J-(K-1)结束时刻)指定时刻之后
int get_beg_time(int J, int K, int after_this_time) {
    int num_mach = mach[J][K];
    int T = TM[J][K];

    for (auto it = mach_available_time[num_mach].begin(); it != mach_available_time[num_mach].end(); ++it) {
        if (it->first >= after_this_time && it->second - it->first >= T) {
            return it->first;
        }
        if (it->first <= after_this_time && it->second - after_this_time >= T) {
            return after_this_time;
        }
    }
}

//对机器ｉ的可用时间中除去[t, t+T)
void update_mach_available_time(int i, int t, int T) {
    for(auto it = mach_available_time[i].begin(); it != mach_available_time[i].end(); ++it) {
        if (it->first <= t && t + T <= it->second) {
            int l = it->first, r = it->second;

            mach_available_time[i].erase(it->first);
            if (l != t) {
                mach_available_time[i][l] = t;
            }
            if (r != t + T) {
                mach_available_time[i][t+T] = r;
            }
            break;
        }
    }
}

//处理J-K这个操作，同时递归处理J-(K-1)
void Oper(int J, int K) {
    int preOperEndTime = 0; //前一个操作的结束时刻
    if (K != 1) {
        preOperEndTime = oper_exec[getId(J, K-1)].second;
    }
    int b = get_beg_time(J, K, preOperEndTime);

    oper_exec[getId(J, K)] = {b, b+TM[J][K]};
    update_mach_available_time(mach[J][K], b, TM[J][K]);
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List106/P1065_in");
#endif
    int cnt[25] = {0}; //累计工件的操作序号(1-1, 1-2)
    int order[500];    //操作序列

    cin >> m >> n;
    for (int i = 1; i <= m * n; ++i) {
        cin >> order[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mach[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> TM[i][j];
        }
    }

    //初始化每台机器的可用时间
    for (int i = 1; i <= m; ++i) {
        mach_available_time[i][0] = INT_MAX;
    }

    //对于序列中的每个工匠操作依次执行
    for (int i = 1; i <= m * n; ++i) {
        int J = order[i];
        int K = ++cnt[J]; //获取工件号(order[i])对应的操作号num_op
        Oper(J, K);
    }

    int max_time = 0;
    for (auto it = oper_exec.begin(); it != oper_exec.end(); ++it) {
        max_time = max(max_time, it->second.second);
    }
    cout << max_time << endl;
    return 0;
}