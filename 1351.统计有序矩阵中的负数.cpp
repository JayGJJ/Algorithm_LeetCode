/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        for (auto ele:grid)
        {//对每一行进行二分查找
            int l = -1,r = ele.size();
            while (l+1<r)
            {//找到第一个负数的位置r
                int m = l+r;
                int num = ele[m];
                if (num>=0)
                {
                    l = m;
                }else{
                    r = m;
                }
            }//统计本行负数
            sum+=(ele.size()-r);
        }
        return sum;
    }
};
// @lc code=end

