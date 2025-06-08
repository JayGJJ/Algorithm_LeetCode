/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDegress(n+1);//数组开拓为n+1,舍弃0下标，使下标和人物编号对应
        vector<int> inDegrees(n+1);//存储图的入度和出度
        for (auto& edge : trust)
        {
            ++inDegrees[edge[1]];//记录各节点的入度和出度，在对应位置上++
            ++outDegress[edge[0]];
        }
        for (int i = 1;i<= n;i++)
        {//从下标1开始遍历(舍弃0下标)，遇到出度为0，入度为n-1的编号直接返回
            if (inDegrees[i] == n-1 && outDegress[i]==0)
            {
                return i;
            }
        }
        return -1;//否则无法官，返回-1
    }
};
// @lc code=end

