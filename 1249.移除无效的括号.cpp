/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public://时间O(n),空间O(1) (不算返回的字符串)
    string minRemoveToMakeValid(string s) {
        string newStr = "";//存储新字符串
        int lbra = 0;
        int rbra = 0;
        for (int i = 0; i < s.size(); i++)
        {//记录右括号的数量
            if (s[i]==')')rbra++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]=='(')
            {//遍历到'('字符时，若后面还有右括号则加入字符串，否则丢弃
                if (rbra>0)
                {
                    newStr+='(';
                    lbra++;
                    rbra--;//左括号数量+1，同时消耗掉一个右括号
                }
            }else if (s[i]==')')
            {//遍历到')'时，若前面已有左括号，则加入字符串，否则丢弃
                if (lbra>0)
                {
                    newStr+=')';
                    lbra--;//消耗掉一个字符串
                }else{
                    rbra--;//消耗掉一个字符串
                }
            }else{
                newStr+=s[i];//除括号以外的字符直接加入字符串
            }
        }
        return newStr;
    }
};
// @lc code=end

