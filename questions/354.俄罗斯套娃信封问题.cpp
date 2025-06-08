/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public://采用动态规划
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (!n)return 0;//数组为空直接返回
        sort(envelopes.begin(),envelopes.end(),[](const auto&e1,const auto&e2){
            return e1[0]<e2[0]||(e1[0]==e2[0]&&e1[1]>e2[1]);
        });//对数组进行排序,采用宽度升序，高度降序排列(宽度相同时高度小的在前，保证相同宽度信封不会套上)
        vector<int> f = {envelopes[0][1]};//此数组记录下标+1的LIS中最小元素(贪心),初始置入首位元素
        for (int i = 1; i < n; i++)//首位元素已放入数组，因此从下标1开始
        {
            int h = envelopes[i][1];//取得当前高度
            if (h>f.back())
                f.push_back(h);//若当前高度大于末尾的元素，则可以装下此前记录的信封
            else
            {
                auto it = lower_bound(f.begin(),f.end(),h);
                //找出大于h的最小元素进行替换(贪心)，使后续的信封尽可能地多
                *it = h;
            }
        }
        return f.size();//数组的长度即为LIS
    }
};
// @lc code=end

