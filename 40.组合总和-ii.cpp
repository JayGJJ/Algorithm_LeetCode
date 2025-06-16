// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:

    void dfs(vector<int>& candidates, int target,int idx,vector<int> &temp,vector<vector<int>> &ans){
        if(target==0)//递归出口
        {
            ans.push_back(temp);
            return;
        }
        for (size_t i = idx; i < candidates.size(); i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])continue;//starred:跳过同一个位置上重复的项
            if(candidates[i]>target)return;
            temp.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1,temp,ans);
            temp.pop_back();
        }   
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,temp,ans);
        return ans;
    }
};
// @lc code=end

