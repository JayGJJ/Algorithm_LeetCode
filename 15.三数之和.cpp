// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//-4 -1 -1 0 1 2
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l=0,m=0,r=0;//工作指针
        int temp=0;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());//升序快排
        while(l<nums.size()-2){
            temp = -nums[l];//满足条件的剩下两个数的和等于第一个数的相反数
            m = l+1;r = nums.size()-1;
            while(m<r){//移动到下个不同的数字
                if(temp == nums[m]+nums[r]){//满足条件后跳过重复数字
                    ans.push_back({nums[l],nums[m],nums[r]});
                    while(m<r && nums[m]==nums[m+1])m++;
                    while(m<r && nums[r]==nums[r-1])r--;
                    m++;r--;
                }
                else if(temp < nums[m]+nums[r]){
                    r--;
                }else{
                    m++;
                }
            }
            while(l<nums.size()-2 && nums[l]==nums[l+1])l++;
            l++;
        }
        return ans;
    }
};
// @lc code=end

