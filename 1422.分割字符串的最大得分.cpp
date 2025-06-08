/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int score = 0;//记录初始位置(下标为1)时的得分
        int n = s.size();
        if (s[0]=='0')score++;//计算左边0的数量和右边1的数量
        for (int i = 1; i < n; i++)
        {
            if (s[i]=='1')score++;
        }
        int curSco = score;
        for (int i = 1; i < n-1; i++)
        {//向右依次移动，遇到1分数-1，0分数+1
            if (s[i]=='1')
            {
                curSco--;
            }else{
                curSco++;
            }
            //记录遍历过程中的最大值
            score = max(curSco,score);
        }
        return score;
    }
};
// @lc code=end

