//
// Created by sacred on 20-4-19.
//


// https://www.luogu.com.cn/problem/P3374

/**
 * 【模板】树状数组 1
 *
 *  需要对一个数组，执行如下的两种操作
 *　
 *  (1) 将某一个数加上ｘ
 *  (2) 求出某个区间的全部数的和
 *　
 * 对于这两种操作，可以使用树状数组来求解
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 10;
int arr[maxn];

//110 --> 10, 11100100 --> 100
int lowbit(int x)
{
  return -x & x;
}

// 求查询区间(0, r]的和，其实在树状数组中索引都是从１开始的.
// d[] 是树状数组，其每个存储的是原始数组的某些位置的和．例如d[2]存储的arr[1] + arr[2]的和
int query(int *d, int r)
{
    int sum = 0;
    while(r) {
        sum += d[r];
        r -= lowbit(r);
    }
    return sum;
}

// 在d[i]的位置上加上ｙ. d[]的长度为n
void add(int *d, int n, int i, int y)
{
    while(i <= n) {
        d[i] += y;
        i += lowbit(i);
    }
}

int main(int argc, char **argv)
{
    memset(arr, 0, sizeof(arr));

    int n, m;
    cin >> n >> m;

    for (int i = 1, t; i <= n; ++i) {
        cin >> t;
        add(arr, n, i, t);
    }
    int op, i, j;
    while(cin >> op >> i >> j) {
        if (op == 1) {
            add(arr, n, i, j);
        } else {
            cout << query(arr, j) - query(arr, i-1) << "\n";
        }
    }

    return 0;
}

/*
input:
5 5
1 5 4 2 3
1 1 3
2 2 5
1 3 -1
1 4 2
2 1 4

output:
14
16
 */