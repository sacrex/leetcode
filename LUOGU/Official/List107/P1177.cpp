//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[100005];

void Sort(int A[], int, int);
void QuickSort(int A[], int, int);

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
//    Sort(A, 0, n-1);
    QuickSort(A, 0, n-1);
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    return 0;
}

/// 二分法，取中间值作为pivot

void Sort(int A[], int begin, int end) {
    if (begin >= end) return;

    int pivot = A[(begin + end) / 2];
    int i = begin, j = end;
    while(i < j) {
        while(A[i] < pivot) i++;
        while(A[j] > pivot) j--;
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (begin < j) Sort(A, begin, j);
    if (i < end) Sort(A, i, end);
    return;
}

/// 传统的快速排序
/// 算法正确，但是对重复序列或已排序的序列排序的性能差

void QuickSort(int A[], int begin, int end) {
    if (begin >= end) return;

    int l = begin, r = end, pivot = A[l];
    while(l < r) {
        while (l < r && A[r] >= pivot) r--;
        if (A[r] < pivot) {
            A[l] = A[r];
        }
        if (l == r) break;

        while(l < r && A[l] <= pivot) l++;
        if (A[l] > pivot) {
            A[r] = A[l];
        }
        if (l == r) break;
    }
    A[l] = pivot;

    QuickSort(A, begin, l-1);
    QuickSort(A, l+1,   end);
}