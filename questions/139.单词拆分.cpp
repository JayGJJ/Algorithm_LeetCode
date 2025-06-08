/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Set;//利用hash表存储字符串，以便快速查找
        for (string& s:wordDict)
        {//将字符串加入hash表
           Set.insert(s);
        }
        int n = s.size();//字符串长度
        //由于第一个位置用来记录空字符串，因此总长度+1
        vector<bool> dp(n+1);//dp数组，记录当前位置前的字符串是否能被分割成多个表中的字符串
        dp[0] = true;//首位置为true，即空串时成立
        for (int i = 1; i <= n; i++)
        {//依次遍历每一个字符
            for (int j = 0; j < i; j++)
            {//验证当前位置前的字符串能否被分割为多个已存在字符
               if (dp[j] && Set.find(s.substr(j,i-j))!=Set.end())
               {
                    dp[i] = true;
               }
            }
        }
        return dp[n];
    }
};
// @lc code=end

