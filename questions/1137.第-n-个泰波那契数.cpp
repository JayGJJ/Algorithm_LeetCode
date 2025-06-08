/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if (n<=2)return (n+1)/2;
        int first = 0,second = 1,third = 1;
        for (int i = 3; i <= n; i++)
        {
            int fourth = first+second+third;
            first = second;
            second = third;
            third = fourth;
        }
        return third;
    }
};
// @lc code=end

