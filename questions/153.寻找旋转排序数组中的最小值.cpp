/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public://迭代
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        int minNum = __INT_MAX__;//记录最小值
        while (l<=r)
        {
            int mid = (l+r)/2;
            int minTemp = 0;
            if (nums[l]<=nums[mid])
            {
                minTemp = nums[l];//记录当前有序的一半数组中的最小值
                l = mid+1;//继续查找另一半无序数组
            }else{
                minTemp = nums[mid+1];
                r = mid;
            }
            minNum =min(minNum,minTemp);//记录最小值 
        }
        return minNum;
    }
};
// @lc code=end

