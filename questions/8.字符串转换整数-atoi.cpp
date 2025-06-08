// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem8.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i=0,sign = 1;//字符数组下标
        string num = "";//返回结果
        while(i<s.size() && s[i]==' ')i++;//到达第一个非空格数字
        if(i==s.size())return 0;
        if(s[i]=='-')sign = -1;
        if(s[i]=='-'||s[i]=='+')i++;//判断符号
        while(i<s.size() && isdigit(s[i])){
            num += s[i];
            i++;
        }
        if(num.size()==0)return 0;
        long ans;
        try
        {
            ans = stoll(num)*sign;
        }
        catch(const std::exception& e)
        {
            if(sign<0)return INT_MIN;
            else return INT_MAX;
        }
        if(ans>INT_MAX)return INT_MAX;
        else if(ans<INT_MIN)return INT_MIN;
        else return (int)ans;
    }
};
// @lc code=end

