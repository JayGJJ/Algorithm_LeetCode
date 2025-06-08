/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //右边界，从第一个不小于x的数起
        int right = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        //左边界
        int left = right - 1;
        while (k--)//循环k个数
        {
            if (left<0)right++;//左边界已超出界限，只移动右节点
            else if (right>=arr.size())left--;//右边界已超出界限，只移动左节点
            //若left的数更靠近，则移动left，否则移动right
            else if (x-arr[left]<=arr[right]-x)left--;
            else right++;   
        }
        //返回所移动的区间
        return vector<int>(arr.begin()+left+1,arr.begin()+right);
    }
};
// @lc code=end

