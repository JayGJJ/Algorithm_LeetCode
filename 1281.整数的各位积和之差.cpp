/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int multi = 1;
        while (n>0)
        {
            sum += n%10;
            multi *= n%10;
            n/=10;
        }
        return multi-sum;
    }
};
// @lc code=end

