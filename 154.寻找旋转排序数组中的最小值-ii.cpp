/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1;    
        while (l<r)
        {
            int mid = l+(r-l)/2;
            if (nums[mid]>nums[r])
            {//左半边为顺序序列，忽视
                l = mid+1;
            }else if(nums[mid]<nums[r])
            {//右半边为顺序序列，忽视,但要将mid下标纳入左半边
                r = mid;
            }else{//相等则不确定，去除掉一个相等的值
                r-=1;
            }
        }
        return nums[l];
    }
};
// @lc code=end