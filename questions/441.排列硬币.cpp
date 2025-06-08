/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        int rowNum = 0;//记录可形成的行数
        while (low<=high)//循环至low>high
        {
            int mid = low+(high-low)/2;
            long ret =(long) (1+mid)*mid/2;
            if (n>=ret)//根据大小逐渐向目标值靠近
            {
                rowNum = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return rowNum;
    }
};
// @lc code=end

