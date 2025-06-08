/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        //dp数组，存储以对应位置为右小角的所能形成的最大正方形的边长
        vector<vector<int>> dp(row,vector<int>(col));
        for (int i = 0; i < col; i++)
        {//设置上边界
            if (matrix[0][i]=='1')dp[0][i] = 1;
        }
        for (int i = 0; i < row; i++)
        {//设置左边界
            if (matrix[i][0]=='1')dp[i][0] = 1;
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {//遍历，进行状态转移
                if (matrix[i][j]=='1'){
                   dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
        int Maxeg = dp[0][0];
        for (int i = 0; i < row; i++)
        {//找出dp数组中的最大值，即为最大正方形的边长
            Maxeg = max(Maxeg,*max_element(dp[i].begin(),dp[i].end()));
        }
        return Maxeg*Maxeg;
    }
};
// @lc code=end

