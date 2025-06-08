/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public://利用二分法查找平方根
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ret = 0;//记录结果
        while (low<=high)//循环至low>high停止
        {
            int mid = low+(high-low)/2;
            long multi =(long)mid*mid;
            if(x>=multi){//记录平方根
                ret = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ret;
    }
};
// @lc code=end

