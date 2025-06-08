/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //对原数组按照距离升序排序
        sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b)
        {return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];});
        //返回前k个元素，(左闭右开区间)
        return {points.begin(),points.begin()+k};
    }
};
// @lc code=end

