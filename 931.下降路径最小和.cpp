/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==1)return matrix[0][0];//验证数据规范
        vector<int> dp(n);//存储和
        vector<int> dptemp(n);//保存临时结果
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j==0)dptemp[j] = min(dp[0],dp[1])+matrix[i][j];//处理首尾列
                else if (j==n-1)dptemp[j] = min(dp[n-2],dp[n-1])+matrix[i][j];
                else dptemp[j] = min(min(dp[j-1],dp[j]),dp[j+1])+matrix[i][j];//找出最小路径和
            }
            dp = dptemp;//更新数组
        }
        return *min_element(dp.begin(),dp.end());//返回最小值
    }
};
// @lc code=end

