// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //对每一行进行二分查找
        for (const vector<int>& v:matrix)
        {
            vector<int>::const_iterator it = lower_bound(v.begin(),v.end(),target);
            if (it!=v.end()&&*it==target)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

