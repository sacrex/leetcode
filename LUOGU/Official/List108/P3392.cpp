//
// Created by sacred on 20-6-25.
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

/// 这道题就是一个组合题，也就是白的行数＋蓝的行数＋红的行数 = 总行数，但是白，蓝，红至少要有１行。
/// 故可以这样做：　假设有５行，那么组合的类别有[1, 1, 3], [1, 2, 2], [1, 3, 1],...
/// 那么分别统计每个组合，计算需要涂的格子数就可以了，最少的就是答案
/// 这里要特别注意：组合中的每个数都必须大于0(至少有１行).

//s[5]表示前５行（下标从１开始）中的各个颜色的格子数
struct S{
   int tot, w, b, r;
}s[55];
int N, M;

int A[55], ans = 100000000;

void dfs(int idx) {
    //这里其实就是３个数的组合，故大于３就可以退出了
    if (idx > 3) return ;

    for (int i = 1; i <= N-2; ++i) { //每种颜色最多涂N-2行,最少需涂１行
        A[idx] = i;
        if (idx == 3) {
            int tot = 0;
            for (int j = 1; j <= 3; ++j) {
                tot += A[j];
            }
            //如果刚好涂了N行,此时A[1]表示白的涂的行数，A[2]表示紧接着蓝的涂的行数,A[3]表示最后红的涂的行数
            if (tot == N) {
                int t1 = s[A[1]].b + s[A[1]].r; //需要涂成白的格子数（s[A[1]]表示的前A[1]行）
                int t2 = (s[A[1] + A[2]].tot - s[A[1]].tot) - (s[A[1] + A[2]].b - s[A[1]].b); //需要涂成蓝的格子数(s[A[1] + A[2]] - s[A[１]]表示就是中间的蓝色的行)
                int t3 = (s[N].tot - s[A[1] + A[2]].tot) - (s[N].r - s[A[1] + A[2]].r); //需要涂成红的格子数(s[N] - s[A[1] + A[２]]表示就是最后的红色的行
                ans = min(ans, t1 + t2 + t3);
            }
        }
        dfs(idx+1);
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        string t;
        cin >> t;
        s[i] = s[i-1]; //拷贝(0..i-1)的数据
        for (int j = 0; j < t.size(); ++j) {
            s[i].tot += 1;
            s[i].w += (t[j] == 'W');
            s[i].b += (t[j] == 'B');
            s[i].r += (t[j] == 'R');
        }
    }

    dfs(1);

    printf("%d\n", ans);

    return 0;
}