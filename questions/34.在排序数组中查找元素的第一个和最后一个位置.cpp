/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public://代码复用
    int binarySearch(vector<int>& nums, int target,bool flag){
        int l = -1;
        int r = nums.size();
        while (l+1<r)
        {
            int mid = (l+r)/2;
            int num = nums[mid];
            if (num<target||(flag&&num<=target))
            {//若flag为true，则范围为大于等于target,否则为大于target
                l = mid;
            }else{
                r = mid;
            }
        }
        return r;//返回大于(等于)target的第一个下标
    }   
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = binarySearch(nums,target,false);//target的第一个下标
        int r = binarySearch(nums,target,true)-1;//target的最后一个下标
        if (l<=r)
        {//校验下标是否合法，若数组为空或不存在目标元素时，可能存在l>r
            return {l,r};
        }
        return {-1,-1};
    }
};
// @lc code=end

