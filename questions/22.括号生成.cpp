// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="";
        backtrack(str,n,n,ans);
        return ans;
    }

    void backtrack(string &cur,int lnum,int rnum,vector<string> &ans){
        if(lnum==0 && rnum==0){
            ans.push_back(cur);//递归出口，括号全部有效
        }
        if(lnum>0){//左括号不受顺序限制，只要还有就能加入字符串
            backtrack(cur+='(',lnum-1,rnum,ans);
            //回溯：移除当前添加的括号，恢复字符串状态，以便进行下一次递归尝试
            cur.erase(cur.size()-1,1);
        }
        if(lnum<rnum){//剪枝：右括号的数量小于左括号数量才能加入
            backtrack(cur+=')',lnum,rnum-1,ans);
            cur.erase(cur.size()-1,1);//回溯
        }
    }
};
// @lc code=end

