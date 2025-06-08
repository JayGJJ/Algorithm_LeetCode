/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //动态规划
        int n = cost.size();
        int pre = 0,last = 0;
        for (int i = 2; i <= n; i++)
        {//采用滚动数组节省空间
            //到达当前阶梯花费取前两个阶梯爬到当前阶梯的最小值
            int curr = min(pre+cost[i-2],last+cost[i-1]);
            pre = last;
            last = curr;
        }
        return last;
    }
};
// @lc code=end