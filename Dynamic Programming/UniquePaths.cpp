//A robot is located at the top-left corner of a m x n grid (marked 'Start' in t
//he diagram below).
//
// The robot can only move either down or right at any point in time. The robot
//is trying to reach the bottom-right corner of the grid (marked 'Finish' in the d
//iagram below).
//
// How many possible unique paths are there?
//
//
//Above is a 7 x 3 grid. How many possible unique paths are there?
//
//
// Example 1:
//
//
//Input: m = 3, n = 2
//Output: 3
//Explanation:
//From the top-left corner, there are a total of 3 ways to reach the bottom-righ
//t corner:
//1. Right -> Right -> Down
//2. Right -> Down -> Right
//3. Down -> Right -> Right
//
//
// Example 2:
//
//
//Input: m = 7, n = 3
//Output: 28
//
//
//
// Constraints:
//
//
// 1 <= m, n <= 100
// It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
//
// Related Topics Array Dynamic Programming

/**
 * 　这个是最简单的dp,开全数组 int[n][m]
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **arr = new int*[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[m];
        }

        for (int i = 0; i < m; ++i) {
            arr[0][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            arr[i][0] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        int ret =  arr[n-1][m-1];
        delete[] arr;
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
#include <iostream>

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::cout << (new Solution())->uniquePaths(m, n) << std::endl;
}