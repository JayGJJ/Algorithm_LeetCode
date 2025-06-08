/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size()+1;
        int len2 = word2.size()+1;
        //创建二维dp数组，dp[i][j]即为word1前i个字母转化为word2前j个字母所需要的步骤
        vector<vector<int>> dp(len1,vector<int>(len2,0));
        for (int i = 0; i < len1; i++)
        {//word1字符全部删除所需要的步骤
            dp[i][0] = i; 
        }
        for (int i = 0; i < len2; i++)
        {//word2字符全部增加所需要的步骤
            dp[0][i] = i; 
        }
        for (int i = 1; i < len1; i++)
        {
            for (int j = 1; j < len2; j++)
            {//依次填充dp数组
            //取增加、删除、替换中最少的一种+1
                dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                if (word1[i-1] == word2[j-1])
                {//若字符相同，则不用+1
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp.back().back();//最后即为所使用的最少操作数
    }
};
// @lc code=end

