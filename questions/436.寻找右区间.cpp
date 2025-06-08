/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution { 
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>> iarr;//存储各区间左值与下标的对应关系
        int n = intervals.size();
        for (size_t i = 0; i < n; i++)
        {
            iarr.emplace_back(intervals[i][0],i);
        }//存储对应关系
        sort(iarr.begin(),iarr.end());//排序后使用二分查找
        vector<int> ret(n,-1);//初始化所有元素为-1,-1为无右区间时下标元素
        for (int i = 0; i < n; i++)
        {   //放回大于等于当前区间右值的下标
            auto index = lower_bound(iarr.begin(),iarr.end(),make_pair(intervals[i][1],0));
            if (index!=iarr.end())
            {//若存在右区间，则记录下标
                ret[i] = index->second;
            }
        }
        return ret;
    }
};
// @lc code=end

