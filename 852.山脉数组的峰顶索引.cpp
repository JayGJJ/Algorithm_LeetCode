/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i]>arr[i+1])return  i;
        }
        return 0;
    }
};
// @lc code=end

