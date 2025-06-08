/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));//初始化数组
        dp[0][0]= grid[0][0];//置入第一个位置数据
        for (int i = 1; i < m; i++)
        {//对边界进行填充，以免后续遍历时数组下标越界
            dp[i][0] = dp[i-1][0]+grid[i][0];   
        }
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {//依次填入各个位置最小取值
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];   
            }
        }   
        return dp[m-1][n-1];//取终点值
    }
};
// @lc code=end

