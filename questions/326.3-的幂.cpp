/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (!n)return false;
        while (n%3==0)
        {
            n/=3;
        }
        return n==1;
    }
};
// @lc code=end

