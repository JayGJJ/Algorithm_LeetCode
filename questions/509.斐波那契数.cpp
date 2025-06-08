/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n<=1)return n;
        int first = 0,second = 1;
        for (int i = 2; i <= n; i++)
        {//滚动数组记录节省空间
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
// @lc code=end

