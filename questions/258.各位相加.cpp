/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        while (num>=10)
        {//num存在两位以上时循环继续    
            int sum = 0;
            while (num>0)//为0时退出循环
            {
                sum += num%10;//记录个位
                num /=10;//去除个位
            }
            num = sum;
        }
        return num;
    }
};
// @lc code=end

