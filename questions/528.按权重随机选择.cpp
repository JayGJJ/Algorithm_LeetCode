/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
using namespace std;
class Solution {
private:
    vector<int> pre;//前缀和数组
public:
    Solution(vector<int>& w){
        partial_sum(w.begin(),w.end(),back_inserter(pre));//计算输入数组的前缀和数组
    }
    
    int pickIndex() {
        int num = rand()%pre.back();//从区间[0,sum-1]区间得到随机数
        return upper_bound(pre.begin(),pre.end(),num)-pre.begin();//得到随机数所在下标
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

