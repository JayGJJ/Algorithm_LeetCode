/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = -1;
        int r = nums.size();
        while (l+1<r)
        {
            int m = (l+r)/2;
            int num = nums[m];
            if (num<target)
            {
                l = m;
            }else if (num>target)
            {
                r = m;
            }else{
                return m;
            }
        }
        return l+1;//如果数组中不存在target，l位置上的元素即为最后一个小于target的元素
    }
};
// @lc code=end

