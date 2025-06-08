/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        //创建dp数组，dp[i][j]即为s[i]到sp[j]的最长回文子序列
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i = n-1; i >= 0; i--)//从后往前，短序列向长序列遍历
        {
            dp[i][i] = 1;//每个字符可形成长度为1的子序列
            for (int j = i+1; j <= n-1; j++)//推出当前子序列所能形成的最长回文子序列长度
            {//如果i,j字符相
                if (s[i]==s[j])dp[i][j] = dp[i+1][j-1]+2;
                else{//若i,j处字符不相等，则i,j必不可能在同一回文子序列
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];//即为最长回文子序列
    }
};
// @lc code=end

