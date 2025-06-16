/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool line[9][9] = {0};
        bool column[9][9] = {0};
        bool block[3][3][9] = {0};
        for (size_t i = 0; i < 9; i++)
        {
           for (size_t j = 0; j < 9; j++)
           {
                char c = board[i][j];
                if(c=='.')continue;
                int num = c-'1';
                if(line[i][num] || column[j][num] || block[i/3][j/3][num])return false;
                else {
                    line[i][num]=true;
                    column[j][num]=true;
                    block[i/3][j/3][num]=true;
                }
           }
        }
        return true;
    }
};
// @lc code=end

