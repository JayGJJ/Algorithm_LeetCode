/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = -1;//从数组外下标开始
        int right = nums.size();
        while (left+1<right)//左右下标相邻时循环结束
        {
            int m = (left+right)/2;//折半查找
            int num = nums[m];
            if (num>target)
            {
                right = m;
            }
            else if(num<target){
                left = m;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }
};
// @lc code=end

