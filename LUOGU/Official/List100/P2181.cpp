//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


/*

int a[100], b[100], c[100], d[100], tmp[100], ans[100], N[100];

//两数相加
// a = a + b
void add(int *A, int &A_len, int *B, int B_len)
{
    int i = 0, j = 0, carry = 0;
    while (i < A_len && j < B_len) {
        int t = A[i] + B[j] + carry;
        A[i] = t  % 10;
        carry = t / 10;
        i++;j++;
    }
    while(i < A_len) {
        int t = A[i] + carry;
        A[i++] = t % 10;
        carry = t / 10;
    }
    while(j < B_len) {
        int t = B[j++] + carry;
        A[i++] = t % 10;
        carry = t / 10;
    }
    if (carry) {
        A[i++] = carry;
    }
    A_len = i; //更新a的长度
}

//两数相乘
void multi(int *A, int A_len, int *B, int B_len, int *C, int &C_len)
{
    int tt[100];
    for (int i = 0; i < A_len; ++i) {
        memset(tt, 0, sizeof(tt));

        int carry = 0, j;
        for (j = 0; j < B_len; ++j) {
            tt[i+j] = (A[i] * B[j] + carry ) % 10;
            carry  = (A[i] * B[j] + carry ) / 10;
        }
        if (carry) {
            tt[i + j] = carry;
            add (C, C_len, tt, i + j + 1);
        } else {
            add(C, C_len, tt, i + j);
        }
    }
}

// c = a / T
void divide(int *A, int &A_len, int T, int *C, int &C_len)
{
    int t = 0, k = 0;
    for (int i = A_len - 1; i >= 0; i--) {
        int x = t * 10 + A[i];

        if (x >= T) {
            C[k++] = x / T;
            t = x % T;
        } else {
            C[k++] = 0;
            t = x;
        }
    }
    if (t) {
        C[k++] = t;
    }
    C_len = k;
}

//整数字符串化
void Itoa(int t, int *A, int &A_len)
{
    int i = 0;
    while(t) {
        A[i++] = t % 10;
        t /= 10;
    }
    A_len = i;
}

int main(int argc, char **argv)
{
    // 1-3,1-4,...,1-(n-1),然后分别以该边为分界线，算与该边的交点.然后求和 * n / 4
    int n;
    cin >> n;
    if (n <= 3) {
        cout << 0 << endl;
    }

    memset(ans, 0, sizeof(ans));
    memset(d, 0, sizeof(d));
    memset(N, 0, sizeof(N));

    int d_len = 0, n_len = 0, ans_len = 0;
    for (int i = 3; i <= n - 1; ++i) {
        int left = i - 2, right = n - i;

        int left_len = 0, right_len = 0, c_len = 0;
        Itoa(left, a, left_len);
        Itoa(right, b, right_len);
        multi(a, left_len, b, right_len, c, c_len);

        add(d, d_len, c, c_len);

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    Itoa(n, N, n_len);

    memset(tmp, 0, sizeof(tmp));
    int tmp_len = 0;

    multi(d, d_len, N, n_len, tmp, tmp_len);
    divide(tmp, tmp_len, 4, ans, ans_len);
    for (int i = 0; i < ans_len; ++i) {
        if (i == 0 && !ans[0]) continue;

        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}

*/

/*
 *  98765
 *  3964374251598225115
 *
 *  54685
 *  372575225162604135
 */


/************************************************************************/
// 下面这种方法对　n <= 100000　可以满足
//
// 题解思路：
// 求交点个数－－> 两条对角线确定一个交点--> 即一个交点是有４个顶点确定－－> 那么
// 只需求出ｎ个顶点中有多少４个顶点的组合即可Cn(4),即为答案。
//
// 化简可得: ans = (n) * (n-1) * (n-2) * (n-4) / 24
//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char **argv)
{
    // 1-3,1-4,...,1-(n-1),然后分别以该边为分界线，算与该边的交点.然后求和 * n / 4
    ull ans = 0;
    int n;
    cin >> n;
    if (n <= 3) {
        cout << 0 << endl;
    }

    for (int i = 3; i <= n - 1; ++i) {
        ull left = i - 2, right = n - i;
        ans += left * right;
    }
    if (ans % 4 == 0) {
        ans /= 4;
        cout << ans * n << endl;
    } else {
        cout << ans * n / 4<< endl;
    }
    return 0;
}