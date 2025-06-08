/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);//创建一维数组，以三角形最长数组元素个数为长度
        dp[0] = triangle[0][0];//置入第一层数据
        for (int i = 1; i < n; i++)
        {//动态规划采用下一层的数据覆盖上一层，节省空间
            dp[i] = dp[i-1]+triangle[i][i];//先置入最后一个元素，以免影响其他元素
            for (int j = i-1; j > 0; j--)
            {//依次更新中间元素
                dp[j] = triangle[i][j] + min(dp[j-1],dp[j]);
            }//更新第一个元素
            dp[0] = dp[0] + triangle[i][0];
        }//返回数组(即为最后一层元素)中的最小值
        return *min_element(dp.begin(),dp.end());
    }
};
// @lc code=end

