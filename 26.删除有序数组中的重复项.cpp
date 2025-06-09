// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int fast=0,low=0;
        while(fast<nums.size()){//移动到下一个不相等的元素
            if(nums[low]!=nums[fast])nums[++low] = nums[fast];
            fast++;
        }
        return low+1;
    }
};
// @lc code=end

