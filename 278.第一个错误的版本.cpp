/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;//左右边界
        while (low<high)//循环直至左右边界相等
        {
            int mid = low+(high-low)/2;//防止溢出
            if (isBadVersion(mid))high = mid;//如果出错，则范围在[1,mid]间
            else low = mid+1;//否则范围为[mid+1,high]
        }
        return low;//low==high，此时为分界线即为答案
    }
};
// @lc code=end

