//
// Created by sacred on 20-4-19.
//

// https://www.luogu.com.cn/problem/P1908
/**
 *  逆序对
 *
 *  找出一个序列中逆序对的数目
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int maxn = 500000 + 10;
int arr[maxn];
int mergeTemp[maxn]; //merge使用的临时数组

int d[maxn];         //树状数组
int sorted[maxn];    //离散化和排序

// brute force(暴力)　Ｏ(n^2) 25%
void bf()
{
    ios::sync_with_stdio(false);
    memset(arr, 0, sizeof(arr));
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", arr+i);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] > arr[j])
                ans ++;
        }
    }
    printf("%d\n", ans);
}

/***********************************************************************/

// arr[left...mid]和arr[mid+1...right]进行归并排序,并把结果写回arr
void Merge(int *arr, int left, int mid, int right, ll& cnt)
{
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            mergeTemp[k++] = arr[j++];
            cnt += mid - i + 1;
        } else { //arr[i] <= arr[j]
            mergeTemp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        mergeTemp[k++] = arr[i++];
    }
    while (j <= right) {
        mergeTemp[k++] = arr[j++];
    }

    //copy mergeTemp to arr
    for(int i = 0; i < k; ++i)
        arr[left+i] = mergeTemp[i];

    return;
}

// 归并算法 O(nlogn) ac
// 注意计数变量cnt需要long long
// cnt用来计数　逆序对
void mergeSort(int *arr, int left, int right, ll &cnt)
{
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, cnt);
    mergeSort(arr, mid + 1, right, cnt);

    Merge(arr, left, mid, right, cnt); //merge 过程需要使用一个辅助的数组
}

void mergeSortAns()
{
    memset(arr, 0, sizeof(arr));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    ll ans = 0;
    mergeSort(arr, 0, n-1, ans);

    printf("%lld\n", ans);
}
/***********************************************************************/

/*
 *  离散化的的含义：只关心数之间的大小关系，维护这样一个关系就可以了。
 *  例如 9, 8, 7, 7, 4这样一个数组，我们可以排序，去重，然后，离散化处理
 * 　得到　4, 3, 2, 2, 1这样一个数组。
 * 　因为　排序后的数组为4, 7, 7, 8, 9,去重为4, 7, 8, 9,因此４在索引１,9在索引4处。所以对原数组来说,
 *  　9就是４(最大)，８就是3, 7就是２，４就是１（最小）
 */

int lowbit(int x)
{
    return -x & x;
}

ll query(int r)
{
   ll ans = 0;
    while (r)
    {
        ans += d[r];
        r -= lowbit(r);
    }
    return ans;
}

ll add(int *d, int len, int i, int t)
{
    while (i <= len) {
        d[i] += t;
        i += lowbit(i);
    }
}

//树状数组的解法
/**
 *  思路：
 *  因为逆序对是说，一个元素与向前的（索引至较小的）元素比较，若比它小，则构成一个逆序对.
 *  因此假设我们现在有一个数组，已经读入了前面的ｋ个元素，并把这些元素放在了另外一个数组对应的
 *  位置上．例如，读入一个arr[i],那么把arr[i]放在另一个数组的索引值为arr[i]处。如果现在读入了一个
 *  新的元素，那么我们只要计算出比这个元素大的元素有多少个就可以了。而比该元素大的都已经存放在了另一个数组
 *  对应的位置上。
 *
 *  例子：如果输入一个数组为 5, 4, 2, 6, 3, 1.　我们维护另一个数组d，该数组用于存放输入的元素在对应位置上的次数
 *  那么读入一个５,那么在ｄ这个数组索引处为5的地方加１。同时我们看一下比５大的数有哪些，只需从索引６开始找，直到数组的最后。
 *  把比５大的数出现的次数都加起来就是　那些和５构成逆序的元素生成的逆序数。
 *  由于５是第一个元素，还没有比他大数。因此逆序数加０，并且把５存入到ｄ中，也就是d[5] += 1,同时ｄ作为一个树状数组来维护，
 *  因为当４读入的时候，我们需要计算比４大的数出现的次数，那么就可以用d[6]-d[4]这样来计算。因为d[6]包含了１到６这６个元元素
 *  出现的和，而d[4]包含了１到４这４个元素出现的次数，因此d[6]-d[4]在意思就是５和６这两个元素出现的次数，也就是和4构成的逆序对数目
 *  所以d数组用树状数组来维护的话，计算一个区间的就很快了.
 */
void BitAns()
{
    memset(d, 0, sizeof(d)); //对树状数组清０，因为query操作会查寻元素的值.

    int n;
    scanf("%d\n", &n);

    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
        sorted[i] = arr[i];
    }

    //离散化处理
    sort(sorted+1, sorted+n+1);
    int m = unique(sorted+1, sorted+n+1) - (sorted+1); //m表示的是无重复的元素的个数
    for (int i = 1; i <= n; ++i) {
        arr[i] = lower_bound(sorted+1, sorted+m+1, arr[i]) - sorted; //离散化arr[i](前面有离散化讲解), 减去sorted,而不是sorted+1,表示索引从１开始
    }

    for (int i = 1; i <= n; ++i) {
        ans += query(m) - query(arr[i]); // m表示的是序列中最大的元素(整个序列，不仅是当前已经读入的数)对应的树状数组的索引
        // query(MAX) - query(arr[i])就是计算当前已经读入的数（当然在输入序列中排在arr[i]的前面）中比arr[i]大的那些元素的个数，这些就构成了逆序对
        add(d, m, arr[i], 1); //把arr[i]插入到树状数组中，也就是arr[i]这个元素出现的次数需要加１，即d[arr[i]] += 1,同时对其祖先节点也要更新d[arr[i] + lowbit(arr[i])] += 1, ...
    }

    printf("%lld\n", ans);
}

int main(int argc, char **argv)
{
//    bf();
//    mergeSortAns();
    BitAns();
    return 0;
}