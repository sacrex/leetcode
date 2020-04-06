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
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int *d = new int[nums.size() + 1];

        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        d[0] = nums[0];
        int Max = d[0];
        for (int i = 1; i < nums.size(); ++i) {
            d[i] = max(d[i-1] + nums[i], nums[i]);
            Max = max(Max, d[i]);
        }
        delete[] d;
        return Max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    return 0;
}