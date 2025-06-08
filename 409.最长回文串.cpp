/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include <string>
using namespace std;
#include <unordered_map>
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> count;//建立hash表存储各字母出现个数
        int ret = 0;//统计回文字符个数
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;//遍历字符串统计字符出现个数
        }
        for (auto p:count)
        {
            ret += p.second/2*2;//每对相同字符可以加入回文串
        }
        if (ret!=s.size())ret++;//当剩余字符时，添加一个作回文中心
        return ret;
    }
};
// @lc code=end

