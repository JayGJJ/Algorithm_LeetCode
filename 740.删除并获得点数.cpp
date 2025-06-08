/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
private:
    int rob(vector<int>& nums){
        int n = nums.size();
        int first = nums[0];
        int second = nums[1];
        //动态规划各数量房间时所能取得的最大金额
        for (int i = 2; i < n; i++)
        {//采用滚动数组节省空间
            int third = max(first+nums[i],second);
            first = second;
            second = third;
        }
        return second;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size()<2)return nums[0];
        
        int maxVal = 0;
        for (int val:nums)
        {//找到数组中的最大值
            maxVal = max(maxVal,val);
        }
        //以nums数组中的值作为下标创建数组
        vector<int> sum(maxVal+1);
        for (int val:nums)
        {//计算下标在nums中的数字之和
            sum[val] += val;
        }
        //题意即相邻数字不能取，即可转化为打家劫舍问题
        return rob(sum);
    }
};
// @lc code=end

