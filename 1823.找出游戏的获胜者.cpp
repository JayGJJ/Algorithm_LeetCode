/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
#include<queue>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for (int i = 0; i < n; i++)
        {//将全部元素加入队列
            que.emplace(i+1);
        }
        while (que.size()>1)//队列中仅剩一个元素时停止循环
        {
            for (int i = 0; i < k-1; i++)
            {//循环k-1次
                que.emplace(que.front());
                que.pop();
            }
            que.pop();//最后一次所在的元素直接移除，不进入队列
        }
        return que.front();//最后队列中唯一剩下的便是获胜者
    }
};
// @lc code=end

