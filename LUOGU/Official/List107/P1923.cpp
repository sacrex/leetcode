//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

/// 添加编译器优化
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")


typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

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

/// TLE
vector<int> radixQueue[10];
void RadixSort(vector<int> &A) {
    int radix = 1;

    for (int i = 0; i < 10; ++i) {
        radixQueue[i].clear();
    }

    for (int i = 0; i < 10; ++i) {
        if (i) radix *= 10;

        for (int j = 0; j < A.size(); ++j) {
            radixQueue[A[j] / radix % 10].push_back(A[j]);
        }

        int cnt = 0;
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < radixQueue[j].size(); ++k) {
                A[cnt++] = radixQueue[j][k];
            }
            radixQueue[j].clear();
        }
    }
}


/// 找第k小的数(k >= 0)
/// 用scanf输入可以AC, cin的话TLE
int a[5000005];
int findK(int A[], int left, int right, int k) {
    if (left == right && k == 0) {
        return A[left];
    }

    srand(NULL);
    int seed = rand() % (right - left + 1) + left;
    swap(A[left], A[seed]);

    //////////////////////////////////////////////////
    // 这一段代码就是一趟排序处理
    int l = left, r = right, pivot = A[l];
    while (l < r) {
        while (l < r && A[r] >= pivot) r--;
        if (A[r] < pivot) {
            A[l] = A[r];
        }
        if (l == r) break;

        while (l < r && A[l] <= pivot) l++;
        if (A[l] > pivot) {
            A[r] = A[l];
        }
        if (l == r) break;
    }
    A[l] = pivot;
    /////////////////////////////////////////////////////

    if (k == l - left) {
        return pivot;
    } else if (k > l - left) {
        return findK(A, l+1, right, k - (l - left) - 1);
    } else {
        return findK(A, left, l-1, k);
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    // Read(): 803ms
    // scanf(): 1.91ms
    // Read(利用Buf数组) + 编译优化: 374ms

    int N, k;
    N = Read();
    k = Read();
    for (int i = 0; i < N; ++i) a[i] = Read();
    int t = findK(a, 0, N-1, k);

    cout << t << endl;


//    方案2: tle

//    int N, k;
//    cin >> N >> k;
//    vector<int> A;
//    A.reserve(N);
//    A.resize(N);
//    for (int i = 0; i < N; ++i) {
//        scanf("%d", &A[i]);
//    }
//    RadixSort(A);
//    cout << A[k] << endl;


//    方案3: ac
    //Read: 650ms
    //scanf: 1.44s
    //Read(利用Buf数组): 486ms
    //Read(利用Buf数组) + 编译优化: 419ms

//    int N, k;
//    N = Read();
//    k = Read();
//    for (int i = 0; i < N; ++i)
//        a[i] = Read();
//
//    nth_element(a, a+k, a+N);
//    cout << a[k] << endl;

    return 0;
}

