/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = start;
        for (int i = 1; i < n; i++)
        {
            ret^=(start+2*i);
        }
        return ret;
    }
};
// @lc code=end

