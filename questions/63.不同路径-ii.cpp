/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        if (!obstacleGrid[0][0])
        {//根据原数组设置初值
            dp[0][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {//设置边界值
        //若当前无障碍且前1个位置能到达则设为1，否则为0
            if (!obstacleGrid[i][0]&&dp[i-1][0])
            {
                dp[i][0] = 1;
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (!obstacleGrid[0][j]&&dp[0][j-1])
            {
                dp[0][j] = 1;
            }
        }    
        for (int i = 1; i < m; i++)
        {//当前位置路径，为上左两格路径之和
            for (int j = 1; j < n; j++)
            {
                if (!obstacleGrid[i][j])
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};
// @lc code=end

