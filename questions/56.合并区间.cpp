/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
#include <numeric>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merger;
        for (int i=0;i<intervals.size();i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
           if (!merger.size()||merger.back()[1]<left)
           {
                merger.push_back({left,right});
           }else{
                merger.back()[1] = max(merger.back()[1],right);
           }
           
        }
        return merger;
    }
};
// @lc code=end

