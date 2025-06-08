// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <unordered_set>
using namespace std;
class Solution {
public://滑动窗口
    int maxLen = 0;//记录最大不重复子串长度
    unordered_set<char> hash;//记录出现字符
    int lengthOfLongestSubstring(string s) {
        for(int l=0,r=0;r<s.size();l++){//每轮左边界移动一个位置
            while(!hash.count(s[r]) && r<s.size()){
                //右边界所在元素不重复且右边界仍在范围内
                hash.insert(s[r]);//加入子串
                r++;
            }
            maxLen = max(maxLen,r-l);
            hash.erase(s[l]);//去除左边界元素后移动
        }
        return maxLen;
    }
};
// @lc code=end

