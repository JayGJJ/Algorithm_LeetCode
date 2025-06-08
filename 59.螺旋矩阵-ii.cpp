/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));
        int loop = n/2;//循环的圈数
        int startX = 0;//循环起始X轴
        int startY = 0;//循环起始Y轴
        int numbers = 1;//填充数字
        int i,j;
        while (loop--)
        {
            i = startX;
            j = startY;
            //对矩形上边进行填充
            for (; j < n-startY-1; j++)
            {
                v[startX][j] = numbers++;
            }
            //对矩形左边进行填充
            for (; i < n-startX-1; i++)
            {
                v[i][j] = numbers++;
            }
            //对矩形下边进行填充
            for (; j >startY; j--)
            {
                v[i][j] = numbers++;
            }
            //对矩形左边进行填充
            for (; i > startX; i--)
            {
                v[i][j] = numbers++;
            }
            startX++;
            startY++;
        }
        if (n%2){
            int mid = n/2;//矩形中间的位置
            v[mid][mid] = numbers;
        }
        return v;
    }
};
// @lc code=end

