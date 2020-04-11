//On a 2-dimensional grid, there are 4 types of squares:
//
//
// 1 represents the starting square. There is exactly one starting square.
// 2 represents the ending square. There is exactly one ending square.
// 0 represents empty squares we can walk over.
// -1 represents obstacles that we cannot walk over.
//
//
// Return the number of 4-directional walks from the starting square to the endi
//ng square, that walk over every non-obstacle square exactly once.
//
//
//
//
// Example 1:
//
//
//Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
//Output: 2
//Explanation: We have the following two paths:
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
//2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
//
//
// Example 2:
//
//
//Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
//Output: 4
//Explanation: We have the following four paths:
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
//2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
//3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
//4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
//
//
// Example 3:
//
//
//Input: [[0,1],[2,0]]
//Output: 0
//Explanation:
//There is no path that walks over every empty square exactly once.
//Note that the starting and ending square can be anywhere in the grid.
//
//
//
//
//
//
//
// Note:
//
//
// 1 <= grid.length * grid[0].length <= 20
// Related Topics Backtracking Depth-first Search

#include "common.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        //find start and end
        int si, sj, ei, ej;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    si = i, sj = j;
                } else if (grid[i][j] == 2) {
                    ei = i, ej = j;
                }
            }
        }
        int count = 0;
        dfs(grid, si, sj, ei, ej, count);
        return count;
    }

    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(vector<vector<int>>& grid, int si, int sj, int ei, int ej, int &count)
    {
        if (si == ei && sj == ej) {
            //到达终点,判断是否全部都走过了，除了障碍物
            if (allVisited(grid)) {
                count += 1;
            }
            return;
        }

        grid[si][sj] = 3; //表示该节点以被访问(不会对终点进行设置)

        for(int dir = 0; dir < 4; ++dir) {
            int nx = si + d[dir][0], ny = sj + d[dir][1];
            if (canVisit(grid, nx, ny)) {
                dfs(grid, nx, ny, ei, ej, count);
            }
        }

        //下面这个最重要了，他就是回溯的基础。
        grid[si][sj] = 0; //回溯，并重置该节点为０,使得他可以被其他路径再一次访问到
    }

    bool allVisited(vector<vector<int>> &grid)
    {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool canVisit(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size()) {
            return false;
        }
        if (y < 0 || y >= grid[0].size()) {
            return false;
        }
        if (grid[x][y] == 3) { //已访问节点
            return false;
        }
        if (grid[x][y] == -1) { //障碍物
            return false;
        }
        if (grid[x][y] == 1) { //起点不能在次访问了
            return false;
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
//    vector<vector<int>> v = {{1,0,0,0}, {0,0,0,0}, {0,0,2,-1}}; //2
//    vector<vector<int>> v = {{1,0,0,0}, {0,0,0,0}, {0,0,0,2}};    //4
    vector<vector<int>> v = {{0, 1}, {2,0}}; //0
    cout << Solution().uniquePathsIII(v) << endl;
}
