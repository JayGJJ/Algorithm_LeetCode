// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1)return 0;//若只有一个区间，则直接返回0
        sort(intervals.begin(),intervals.end());//对整体数组进行排序
        int num = 0;//记录删除数组的次数
        vector<int> last = intervals[0];//记录前一个不重叠的区间
        for (int i = 1; i < intervals.size(); i++)//从第二个区间开始判断
        {
            if (intervals[i][0] < last[1])//若当前位置的起始位小于此前最大位置
            {                         //则存在重叠区间，移除
                ++num;
                if (last[1]>intervals[i][1])//再重叠区间中移除右节点更大的区间
                {                           //后面重合的概率更小，符合最优解
                    last = intervals[i];    //若上个区间右节点更大，则将其更新为本区间
                }                           //否则不做处理
            }else{
                last = intervals[i];//若不重叠，则更新区间
            }
        }
        return num;
    }
};
// @lc code=end

