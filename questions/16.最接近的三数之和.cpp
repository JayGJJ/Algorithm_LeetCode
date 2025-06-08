// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem16.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = __INT_MAX__/2,temp = 0;
        sort(nums.begin(),nums.end());//升序快排
        for(int l = 0,m = 0,r = 0;l<nums.size()-2;l++){//固定左边界
            m = l+1,r = nums.size()-1;
            while(m<r){
                temp=nums[l]+nums[m]+nums[r];
                if(abs(temp-target)<abs(ans-target))ans = temp;//取最接近的和
                if(temp==target)return ans;//相等直接返回
                else if(temp<target)m++;//当前值小于target,右移左边界
                else r--;//当前值大于target,左移右边界
            }
        }
        return ans;
    }
};
// @lc code=end

