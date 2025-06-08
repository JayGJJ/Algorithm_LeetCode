/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32; 
        }
        }
        return s;
    }
};
// @lc code=end

