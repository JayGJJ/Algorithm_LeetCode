/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public: 
    bool isPerfectSquare(int num) {
        //使用二分查找寻找平方根
        int low = 0;
        int high = num;
        while (low<=high)
        {
            int mid = (low+high)/2;
            long multi = (long)mid*mid;
            if (multi == num)return true;
            else if(multi < num){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};
// @lc code=end

