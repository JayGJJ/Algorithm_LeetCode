/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n)return -1;//数组无元素时返回-1
        if (n==1)return nums[0]==target?0:-1;//数组只有一个元素时进行检测
        int l = 0,r = nums.size()-1;//左右界限
        while (l<=r)//左下标超过右下标时退出循环
        {
            int mid = (l+r)/2;
            if (nums[mid]==target)return mid;//检测中点是否与目标值相等  
            if (nums[0]<=nums[mid])//如果第一个数组有序
            {
                if (nums[0]<=target&&target<nums[mid])//检查目标值是否在第一部分
                {
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if (nums[mid]<target&&target<=nums[n-1])
                {
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

