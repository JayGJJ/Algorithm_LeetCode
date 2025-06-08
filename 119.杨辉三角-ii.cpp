/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;//滚动数组
        v.resize(rowIndex+1);//将数组扩大为需要的容量
        for (int i = 0; i < rowIndex+1; i++)
        {//滚动到rowIndex+1行
            for (int j = i/2; j >=0; j--)
            {//从中间位置开始往前推,j的对称位置为i-j;
                if (j==0)v[j] = v[i-j] = 1;//当j=0时，首末结点都置为1
                else v[j] = v[i-j] = v[j]+v[j-1];//否则 本行的元素等于相邻两个上行元素相加
            }
        }
        return v;
    }
};
// @lc code=end

