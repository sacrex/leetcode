//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

// sum[block_id]
int sum[105], A[10005];
int block_size, block_cnt, L;

int block_id(int i)
{
    return i / block_size;
}

void remove(int l, int r)
{
    int i = block_id(l), j = block_id(r);
    if (i == j) {
        if (sum[i] == 0) return;

        for (int k = l; k <= r; ++k) A[k] = 0;
        sum[i] = 0;
        for (int k = i * block_size; k <= L && k < (i+1)*block_size; ++k) if (A[k]) sum[i]++;
        return;
    }

    //[i+1, j-1]块直接处理
    for (int k = i + 1; k <= j - 1; ++k) sum[k] = 0;
    //第i块和第j块分别处理
    if (sum[i] != 0) {
        for (int k = l; k < (i + 1) * block_size; k++) A[k] = 0;
        sum[i] = 0;
        for (int k = i * block_size; k < l; ++k) if (A[k]) sum[i]++;
    }
    if (sum[j] != 0) {
        for (int k = j * block_size; k <= r; ++k) A[k] = 0;
        sum[j] = 0;
        for (int k = r + 1; k <= L && k < (j + 1) * block_size; ++k) if (A[k]) sum[j]++;
    }
}

int main(int argc, char **argv)
{
    //FREOPEN("/home/sacred/leetcode/LUOGU/Official/List103/P1047_1.in");

    int m, u, v;
    cin >> L >> m;
    block_size = (int)sqrt(L);
    block_cnt  = (L+1) / block_size + ((L+1) % block_size != 0);
    memset(A, 0x3f, sizeof(A));

    memset(sum, 0, sizeof(sum));
    for (int block_id = 0; block_id < block_cnt - 1; ++block_id) sum[block_id] = block_size;
    for (int i = (block_cnt - 1) * block_size; i <= L; i++) sum[block_cnt-1]++; //最后一块
    while(m--) {
        cin >> u >> v;
        remove(u, v);
    }

    int ans = 0;
    for (int i = 0; i < block_cnt; ++i) {
        ans += sum[i];
    }
    cout << ans << endl;
    return 0;
}