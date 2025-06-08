/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public://斐波那契数列
    int climbStairs(int n) {
        if (n==1)return 1;
        int first = 1,second = 2;
        for (int i = 3; i <= n; i++)
        {//采用滚动数组记录，节省空间
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
// @lc code=end

