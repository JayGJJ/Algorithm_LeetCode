/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //截取前半段和后半段的数字放入两个数组中
        vector<int> second(nums.begin()+n,nums.end());
        vector<int> first(nums.begin(),nums.begin()+n);
        int index = 0;
        for (int i = 0; i < n; i++)
        {//依次填充入两个数组
            nums[index++] = first[i];
            nums[index++] = second[i];
        }
        return nums;
    }
};
// @lc code=end

