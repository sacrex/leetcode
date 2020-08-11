//
// Created by sacred on 20-8-2.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//buf数组缓存数组（预读到buf数组）
char Buf[1 << 16], *p = Buf, *q = Buf;
#define Getchar() (p == q && (q = (p = Buf) + fread(Buf, 1, 1 << 16, stdin), p == q) ? EOF : *p++)
inline int Read() {
    char ch = Getchar();
    int x = 0,f = 1;
    while (ch < '0'|| ch > '9') {
        if(ch=='-')
            f=-1;
        ch = Getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x=10 * x + ch - '0';
        ch = Getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

//group[i]: 第i组的最大数
//group_nums[i]: 第i组共有多少个数
int A[100005], group[100005], group_nums[100005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List110/P4447.in");
    time_t start_time = time(NULL);
#endif

    int n;
    n = Read();
    for (int i = 1; i <= n; ++i) A[i] = Read();
    sort(A+1, A+n+1);

    int ngroup = 0; //多少个组
    for (int i = 1; i <= n; ++i) {
        bool ok = 0;
        //下面这个for循环就是反向遍历每个组，先对长度最小的组进行判断
        for (int j = ngroup; j > 0; --j) {
            if (group[j] + 1 == A[i]) {
                group[j] = A[i];
                group_nums[j]++;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            ngroup++;
            group[ngroup] = A[i];
            group_nums[ngroup]++;
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= ngroup; ++i) {
        ans = min(ans, group_nums[i]);
    }
    cout << ans << endl;

#ifndef ONLINE_JUDGE
    time_t end_time = time(NULL);
    cout << "Cost TIME(s): " << end_time - start_time << endl;
#endif

    return 0;
}

/*
 *   5
 *  -4 -3 -2 -2 -1
 *
 *  分成2组：
 *    -4  -2
 *    -3  -1
 *    -2
 *
 * 故最小长度的组的最大可以有2个元素
 *
 * 过程：
 * 迭代 1       2      3      4          5
 * 组号 1        1      1     1  2       1  2
 *    -4       -4     -4    -4 -2      -4 -2
 *             -3     -3    -3         -3 -1
 *                    -2    -2         -2
 *                                     （迭代到-1的时候，从第二组先匹配）
 */

//下面用另一个方式
// 用map来代替group和group_nums数组
// map<int, priority_queue<int, vector<int>, greater<int>>> 最大值 --> [对应这个最大值的所有队列的长度]
int main2()
{
    map<int, priority_queue<int, vector<int>, greater<int> > > queue;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    sort(A+1, A+n+1);
    for (int i = 1; i <= n; ++i) {
        int t = A[i];
        try {
            auto &pq = queue.at(t-1);
            int l = pq.top(); pq.pop();
            if (pq.empty()) {
                queue.erase(t-1);
            }

            try {
                auto &pq = queue.at(t);
                pq.push(l+1);
            } catch(exception &e) {
                queue[t].push(l+1);
            }

        } catch (exception &e) {
            queue[t].push(1);
        }
    }

    int ans = INT_MAX;
    for (auto it = queue.begin(); it != queue.end(); ++it) {
        ans = min(ans, it->second.top());
    }

    cout << ans << endl;
    return 0;
}
