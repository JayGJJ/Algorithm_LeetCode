/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int width = matrix.size();//矩形的宽度
        for (int i = 0; i < width/2; i++)
        {
            for (int j = 0; j  < width; j ++)
            {
                //将矩形进行上下翻转
                swap(matrix[i][j],matrix[width-i-1][j]);
            }
        }
        for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < i; j++)
                {
                //将矩形沿主对角线翻转
                    swap(matrix[i][j],matrix[j][i]);
                }
                
            }
    }
};
// @lc code=end

