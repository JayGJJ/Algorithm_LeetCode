/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n<2)return nums[0];//数组大小<2,直接返回最大值
        if (n==2)return max(nums[0],nums[1]);
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);//初始置入前两个数据
        for (int i = 2; i < n; i++)
        {//采用动态规划计算出i个房子所能得到的最大值
            dp[i]  = max(dp[i-2]+nums[i],dp[i-1]);
        }//dp数组的最大值即为最高金额
        return dp[n-1];
    }
};
// @lc code=end

