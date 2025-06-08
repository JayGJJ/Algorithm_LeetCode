/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0,right = n-1;
        while (left<=right)//每次移动后都是新的边界，因此要检查left=right的情况
        {
            int mid = (left+right)/2;
            if (citations[mid]<n-mid)
            {//如果当前值小于此后的元素数量，移动左边界
                left = mid+1;
            }else{//若当前值大于等于此后元素的数量，移动右边界
                right = mid-1;
            }
        }
        return n-left;
    }
};
// @lc code=end

