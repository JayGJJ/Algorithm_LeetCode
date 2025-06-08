/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public://时间复杂度为log(n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int RowHigh = row-1;
        int RowLow = 0;
        int aimRow = 0;//目标值所在行
        int colSeq = col-1;
        while (RowLow<=RowHigh)
        {//利用二分查找找出目标值所在行
            int midRow = (RowHigh+RowLow)/2;
            if(target>=matrix[midRow][0]&&target<=matrix[midRow][colSeq]){
                aimRow = midRow;
                break;
            }
            else if (target<matrix[midRow][0])
            {
                RowHigh = midRow-1;
            }else
            {
                RowLow = midRow+1;
            }
        }
        int high = colSeq;
        int low = 0;
        while (low<=high)
        {//利用二分查找寻找目标值
            int mid = (high+low)/2;
            if (matrix[aimRow][mid]==target)return true;
            if (target<matrix[aimRow][mid])
            {
                high = mid-1;
            }else{
                low  = mid+1;
            }
        }
        return false;
    }
};
// @lc code=end

