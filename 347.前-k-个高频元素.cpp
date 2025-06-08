/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
using namespace std;
#include <unordered_map>
#include <queue>
class Solution {
public: //时间复杂度为O(nlogk) 空间复杂度为O(n)
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }//用于优先队列的比较函数
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (auto &ele:nums)map[ele]++;//记录每个数字的出现次数
        //构造优先队列
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> que(cmp);
        for (auto &m:map)
        {//若当前堆的大小已经为k，且当前值小于栈顶值，则不加入堆
            if (que.size()>=k&&que.top().second>m.second)continue;
            if (que.size()>=k)
            {//大小为k且需要加入栈时，移除栈顶元素
                que.pop();
            }
            que.emplace(m);
        }
        vector<int> v;
        while (!que.empty())
        {//取出优先队列中的元素放入结果集中
            v.emplace_back(que.top().first);
            que.pop();
        }
        return v;
    }
};
// @lc code=end

