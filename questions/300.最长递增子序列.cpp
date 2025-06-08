/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n)return 0;//如果数组为空直接返回
        vector<int> dp(n,0);//记录当前下标元素所能形成最长递增子序列的长度
        for (int i = 0; i < n; i++)
        {//依次遍历每个元素
            dp[i] = 1;//初始置为1，即只能形成含有一个本身元素的子序列
            for (int j = 0; j < i; j++)
            {//遍历此下标之前的dp数组
                if (nums[j]<nums[i])
                {//若此条件成立，则i可与j形成递增子序列
                    dp[i] = max(dp[i],dp[j]+1);//将当前长度与i和j形成的长度作比较，取最大值
                }
            }           
        }
        return *max_element(dp.begin(),dp.end());//dp中的最大值即为最长子序列长度
    }
};
// @lc code=end

