/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //pos表示当前访问数字下标
    void dfs(vector<int>& candidates, int target,int pos,vector<int>& temp,vector<vector<int>>& ans){
        if(pos == candidates.size())return;//递归出口:元素已经访问完毕，返回
        if(target == 0){//数字组合满足条件直接返回
            ans.push_back(temp);
            return;
        }
        for (size_t i = pos; i < candidates.size(); i++)
        {
            if(candidates[i]>target)return;//剪枝
            temp.push_back(candidates[i]);
            //由于元素可重复使用，故仍然传入i下标
            dfs(candidates,target-candidates[i],i,temp,ans);
            temp.pop_back();//回溯
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;//结果
        vector<int> temp;//存储可能的数字组合
        sort(candidates.begin(),candidates.end());//排序以更好组合
        dfs(candidates,target,0,temp,ans);
        return ans;
    }
};
// @lc code=end

