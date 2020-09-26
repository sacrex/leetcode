//
// Created by sacred on 20-8-30.
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

int A[15], K1[30], K2[30], K[20];
int cnt;

bool check(int row, int col)
{
    // A[i] 表示 第i行的元素位于A[i]列
    for (int i = 1; i < row; ++i) {
        //比较(i, A[i]) 和 (row, col)
        if (col == A[i]) {
            return false;
        }

        // 对角线
        if (A[i] + row == i + col || A[i] + i == row + col) {
            return false;
        }
    }
    return true;
}

void dfs(int n, int row)
{
    if (row == n + 1) {
        cnt++;
        if (cnt < 4) {
            for (int i = 1; i <= n; ++i) printf("%d ", A[i]);
            printf("\n");
        }
        return;
    }

    for (int col = 1; col <= n; ++col) {
        if (K1[row-col + n] || K2[col+row] || K[col]) {
            continue;
        }

//        if (check(row, col)) {
            A[row] = col;

            K1[row-col + n] = 1;//正对角线
            K2[col + row] = 1;  //反对角线
            K[col] = 1;         //竖线

            dfs(n, row+1);

            K1[row-col + n] = 0;
            K2[col+row] = 0;
            K[col] = 0;
//        }
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    time_t start_time = time(NULL);
#endif

    int n;
    cin >> n;

    cnt = 0;
    dfs(n, 1);
    cout << cnt << endl;

#ifndef ONLINE_JUDGE
    time_t end_time = time(NULL);
    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}