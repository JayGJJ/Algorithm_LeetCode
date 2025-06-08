/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> L(size,1);//遍历位置左侧数组
        vector<int> R(size,1);//遍历位置右侧数组
        vector<int> ret(size,0);
        for (int i = 1; i < size;i++)//构造左侧数组
        {
            L[i] = L[i-1]*nums[i-1];
        }
        for (int i = size-2; i >= 0; i--)//构造右侧数组
        {
            R[i] = R[i+1]*nums[i+1];
        }
        for (int i = 0; i < size; i++)
        {
            ret[i] = L[i]*R[i];//i位置上的值等于左右数组i位置上值的积
        }
        return ret;
    }
};
// @lc code=end

