/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> newmatrix(col,vector<int>(row));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                newmatrix[j][i] = matrix[i][j];
            }
        }
        return newmatrix;
    }
};
// @lc code=end

