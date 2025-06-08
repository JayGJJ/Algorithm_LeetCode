/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;   
        sort(nums.begin(),nums.end());//对原数组进行排序，方便比较后续元素
        for (int i = 0; i < n; i++)
        {//采用双重循环遍历所有三元组
            for (int j = i+1; j < n; j++)
            {//利用二分法找出第一个可以组成三角形的数，此前的所有数都更小，因此都满足条件
                int left = j+1,right = n-1,k=j;
                while (left<=right)
                {
                    int mid = (left+right)/2;
                    if (nums[i]+nums[j]>nums[mid])
                    {
                        k = mid;//记录当前满足条件的元素下标，随后继续向后查找
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }
                ret += k-j;//将此轮满足条件的三元组数量加入结果集
            }
        }
        return ret;
    }
};
// @lc code=end