/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (size_t i = 0; i < n; i++)//小于等于0的置为n+1
            if(nums[i]<=0)nums[i] = n+1;
        for (size_t i = 0; i < n; i++)
        {//给当前数字对应下标位置处的元素加上负号
            int cur = abs(nums[i]);
            if(cur>0 && cur<n+1)nums[cur-1] = -abs(nums[cur-1]);
        }
        
        for (size_t i = 0; i < n; i++)//小于等于0的置为n+1
            if(nums[i]>0)return i+1;
        return n+1;
    }
};
// @lc code=end

