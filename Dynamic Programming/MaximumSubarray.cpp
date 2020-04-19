//Given an integer array nums, find the contiguous subarray (containing at least
// one number) which has the largest sum and return its sum.
//
// Example:
//
//
//Input: [-2,1,-3,4,-1,2,1,-5,4],
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using
//the divide and conquer approach, which is more subtle.
// Related Topics Array Divide and Conquer Dynamic Programming

/*
 * d[0] = a[0] i == 0
 * d[i] = max(d[i-1] + a[i], a[i]) i >= 1
 *
 */
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
long long int arr[100000];
long long int s[100000];
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return -2147483648;
        }

        if (nums.size() == 1){
            return nums[0];
        }

        int len = nums.size();
        long long int maxsofar = nums[0];

        //1. O(n^3) tle
//         for (int i = 0; i < len; ++i) {
//             for (int j = i; j < len; ++j) {
//
//                 long long int sum = 0;
//                 for (int k = i; k <= j; ++k) {
//                     sum += nums[k];
//                 }
//
//                 maxsofar = max(maxsofar, sum);
//
//             }
//         }

        //2. O(n^2) ac 904ms 7.2M
//         for (int i = 0; i < len; ++i) {
//             long long int sum = 0;
//             for (int j = i; j < len; ++j) {
//                 sum += nums[j];

//                 maxsofar = max(maxsofar, sum);
//             }
//         }

        //3. O(n^2) ac 1808ms 7.9M
        //先加一个辅助数组,arr[i] = sum[nums[0]...nums[i]]
//         memset(arr, 0, sizeof(arr));
//         for (int i = 0; i < len; ++i) {
//             if (i != 0) {
//                 arr[i] += arr[i-1];
//             }
//             arr[i] += nums[i];
//         }
//         for (int i = 0; i < len; ++i) {
//             for (int j = i; j < len; ++j) {
//                 if (i - 1 >= 0) {
//                     maxsofar = max(maxsofar, arr[j] - arr[i-1]);
//                 } else {
//                     maxsofar = max(maxsofar, arr[j]);
//                 }
//             }
//         }

        //4. O(n)
        //使用一个辅助数组 s[i]: 表示已i结尾的连续的最大子数组的和
//         memset(s, 0, sizeof(s));
//         s[0] = nums[0];
//         for(int i = 1; i < len; ++i) {
//             s[i] = max(s[i-1] + nums[i], (long long int)nums[i]);
//             maxsofar = max(maxsofar, s[i]);
//         }

        //5. O(nlogn) ac 8ms 7.2M
        //使用分治算法 n --> (n/2, n/2)
        //考虑左半部分和右半部分，以及跨左右的中间部分
        maxsofar = dac(nums, 0, len -1);

        return maxsofar;
    }

    // divide and conquer
    int dac(vector<int>& nums, int left, int right)
    {
        if (left == right) {
            return nums[left];
        }

        int mid = (left + right) / 2;
        int left_max = dac(nums, left, mid);
        int right_max = dac(nums, mid+1, right);

        // 跨左右的中间部分
        // | - | - | - | - | - | - | - | - | - | - |
        //  left        mid mid+1               right
        //分别计算mid -> left 和 mid+1 -> right 的最大值
        int left_sub_max = nums[mid], left_sum = nums[mid]; //左半部分的最大子数组和（必须要有一个元素在左半部分）
        for (int i = mid-1; i >= left; --i) {
            left_sum += nums[i];
            left_sub_max = max(left_sub_max, left_sum);
        }
        int right_sub_max = nums[mid+1], right_sum = nums[mid+1];
        for (int i = mid+2; i <= right; ++i) {
            right_sum += nums[i];
            right_sub_max = max(right_sub_max, right_sum);
        }

        //三者的最大值
        return max(max(left_max, right_max), left_sub_max + right_sub_max);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    return 0;
}