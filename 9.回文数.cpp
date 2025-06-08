/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int l=0,r=str.size()-1;//左右指针
        while(l<r && l+1!=r){//左指针小于右指针且不相邻
            if(str[l]!=str[r])return false;
            l++;r--;
        }
        if(str[l]!=str[r])return false;
        return true;
    }
};
// @lc code=end

