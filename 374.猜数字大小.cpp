/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high = n;
        while (1)
        {
            int mid = low+(high-low)/2;
            int ret = guess(mid);
            if (!ret)return mid;
            if (ret>0)low = mid+1;
            else high = mid-1;
        }
        return 0;
    }
};
// @lc code=end

