// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={INT_MAX,INT_MIN};
        int n = nums.size(),mid = 0;
        int left1=0,right1=n-1;//采用两次二分法
        int left2=0,right2=n-1;
        while(left1<=right1){
            mid = (left1+right1)/2;
            if(nums[mid]==target && mid<ans[0])ans[0]=mid;
            if(nums[mid]<target)left1 = mid+1;
            else right1 = mid-1;
        }
        while(left2<=right2){
            mid = (left2+right2)/2;
            if(nums[mid]==target && mid>ans[1])ans[1]=mid;
            if(nums[mid]>target)right2 = mid-1;
            else left2 = mid+1;
        }
        if(ans[0]==INT_MAX && ans[1]==INT_MIN){
            ans[0] = ans[1] = -1;
        }
        return ans;
    }
};
// @lc code=end

