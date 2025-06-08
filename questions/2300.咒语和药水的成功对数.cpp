/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());//快速排序，时间复杂度nlogn
        for (int i = 0; i < n; i++)
        {//二分查找，时间复杂度为logn
            int left = 0,right = m;
            while (left<right)
            {
                int mid = left+(right-left)/2;
                long long accumulate = (long long)spells[i]*potions[mid];
                if (accumulate>=success)
                {
                    right = mid;
                }else{
                    left = mid+1;
                }
            }//left = right处即为最小满足条件的数
            spells[i] = m-left;
        }
        return spells;
    }
};
// @lc code=end