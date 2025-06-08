/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0]>k)return k;//当缺少的个数小于第一个元素时直接返回k
        int n = arr.size();
        int low = 0,high = n;
        while (low<high)//循环至low=high,此时即为大于目标值的界限
        {
            int mid = low+(high-low)/2;
            int ret = mid<n?arr[mid]:__INT_MAX__;//如果超出最后一个元素，则赋为最大值
            if (k>ret-mid-1)//当前值小于目标值,向右移动界限
            {
                low = mid+1; 
            }else{
                high = mid;//当前值大于等于目标值,移动右边界
            }
        }
        return k-(arr[low-1]-low+1-1)+arr[low-1];
    }
};
// @lc code=end

