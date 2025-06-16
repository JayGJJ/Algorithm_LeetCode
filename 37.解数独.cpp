// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem37.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
     bool line[9][9]={false};
     bool column[9][9]={false};
     bool block[3][3][9]={false};
     bool valid = false;
     vector<pair<int,int>> spaces;
public:
    void dfs(vector<vector<char>>& board,int pos){
        if(pos==spaces.size()){//递归出口 填写完所有空格
            valid = true;
            return;
        }
        auto [i,j] = spaces[pos];//访问空格
        for (size_t num = 0; num < 9; num++)
        {//试图填写数字
            if(!valid && !line[i][num] && !column[j][num] && !block[i/3][j/3][num]){
                line[i][num]=true,column[j][num]=true,block[i/3][j/3][num]=true;
                board[i][j] = num+'1';
                dfs(board,pos+1);
                if(!valid){
                    line[i][num]=false,column[j][num]=false,block[i/3][j/3][num]=false;//回溯
                    board[i][j] = '.';
                }
            }
        }
        
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (size_t i = 0; i < 9; i++)
        {
           for (size_t j = 0; j < 9; j++)
           {
                if(board[i][j]=='.'){
                    spaces.push_back({i,j});
                }else{
                    int num = board[i][j]-'1';
                    line[i][num] = true;
                    column[j][num] = true;
                    block[i/3][j/3][num] = true;
                }
           }
           
        }
        dfs(board,0);
    }
};
// @lc code=end

