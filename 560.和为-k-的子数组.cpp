/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
using namespace std;
#include <unordered_map>
class Solution {
public://时间复杂度O(n)，遍历一遍数组,空间复杂度O(n),利用了一个前缀和数组
    int subarraySum(vector<int>& nums, int k) {
        int length = nums.size();
        int count = 0;//记录符合和为k的子数组数量
        unordered_map<int,int> hashmap;//利用hash表建立前缀和数组
        int pre = 0;
        hashmap[0] = 1;//初始将和为0的位置值为1
        for (int i = 0; i < length; i++)
        {   
           pre+=nums[i];//计算当前位置的前缀和
           if (hashmap.find(pre-k)!=hashmap.end())
           {//如果pre[i]之前存在差为k的pre[j]，则加上其对应的个数
                count+=hashmap[pre-k];
           }
           hashmap[pre]++;//最后将hash表中对应和的数量+1
        }
        return count;
    }
};
// @lc code=end

