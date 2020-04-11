//A robot is located at the top-left corner of a m x n grid (marked 'Start' in t
//he diagram below).
//
// The robot can only move either down or right at any point in time. The robot
//is trying to reach the bottom-right corner of the grid (marked 'Finish' in the d
//iagram below).
//
// Now consider if some obstacles are added to the grids. How many unique paths
//would there be?
//
//
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
//Input:
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//Output: 2
//Explanation:
//There is one obstacle in the middle of the 3x3 grid above.
//There are two ways to reach the bottom-right corner:
//1. Right -> Right -> Down -> Down
//2. Down -> Down -> Right -> Right
//
// Related Topics Array Dynamic Programming

/**
 *  有障碍物的格子，到达该格子的路径就是０。
 *
 *  同样, arr[i][j] = arr[i-1][j] + arr[i][j-1]
 *  并且arr[i][j]的值要修改为0（若(i,j)处是障碍物）
 *　需要考虑 (0,0)处是障碍物的情况
 */

#include "common.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int m = obstacleGrid[0].size(), n = obstacleGrid.size();

        vector<vector<long long>> vv; //中间值存在溢出，故利用long long代替int
        vv.resize(n);
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vv[i].push_back(obstacleGrid[i][j]);
            }
        }

        int o = -1;
        for (int i = 1; i < m; ++i) {
            if (vv[0][i] == 0) {
                vv[0][i] = 1;
            } else {
                o = i;
                break;
            }
        }
        if (o != -1) {
            for (int i = o; i < m; ++i) {
                vv[0][i] = 0;
            }
        }

        o = -1;
        for (int i = 1; i < n; ++i) {
            if (vv[i][0] == 0) {
                vv[i][0] = 1;
            } else {
                o = i;
                break;
            }
        }
        if (o != -1) {
            for (int i = o; i < n; ++i) {
                vv[i][0] = 0;
            }
        }

        vv[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (vv[i][j] == 1) {
                    vv[i][j] = 0;
                } else {
                    vv[i][j] = vv[i-1][j] + vv[i][j-1];
                }
            }
        }
        return vv[n-1][m-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    /*
    vector<vector<int>> v = {
            {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                            {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
                                    {1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
                                            {0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},{0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},{1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},{1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}};
    */
    vector<vector<int>> v;
    cout << Solution().uniquePathsWithObstacles(v) << endl;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            cout << setw(10) << setiosflags(ios::left) <<v[i][j] << " ";
        }
        cout << endl;
    }
}
