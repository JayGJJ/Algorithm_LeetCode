/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ret;//结果集
        vector<int> inDegree(n,0);//提前开辟n大小的空间
        for (auto &ele : edges)
        {//遍历所有边，记录下所有节点的出度和入度
            inDegree[ele[1]]++;
        }
        for (int i = 0; i < n; i++)
        {//将入度为0的节点加入结果集
            if (0 == inDegree[i])
            {
                ret.emplace_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end

