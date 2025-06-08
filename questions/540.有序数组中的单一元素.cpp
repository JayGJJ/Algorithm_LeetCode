/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while (low<high)//循环至low=high时，low即为单独数出现位置
        {
            int mid = (low+high)/2;
            mid -= mid&1;//确保下标为偶数
            if (nums[mid]==nums[mid+1])
            {//当前偶数下标若等于后一个下标，则单独数在后半部分
                low = mid+2;
            }else{
                high = mid;
            }
            
        }
        return nums[low];
    }
};
// @lc code=end

