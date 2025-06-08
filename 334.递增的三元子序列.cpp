/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0];//初始第一个数置为first
        if (nums.size()<3)return false; 
        
        int second = __INT_MAX__;//初始第二个数置为无穷大
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (num>second)return true;//若当前的数字大于second,则找到递增子序列
            else if (num>first)
            {
                second = num;
            }else{
                first = num;
            }   
            
        }
        return false;
    }
};
// @lc code=end

