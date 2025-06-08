/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        string str_reverse = "";
        int i = str.size()-1;;//原数组中的下标 从最后一位开始
        if(str[0]=='-')str_reverse += '-';//考虑负数情况
        while(!str[i]){//跳过逆转后前置的0
            i--;
        }
        while(i>0){
            str_reverse += str[i];
            i--;
        }
        if(str[0]!='-')str_reverse += str[0];
        long temp = stol(str_reverse);
        if(temp> __INT_MAX__||temp<-__INT_MAX__-1)return 0;
        return temp;
    }
};
// @lc code=end

