
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <string>
using namespace std;
#include <algorithm>
class Solution {
public:
    string multiply(string num1, string num2) {
        int i = num1.size()-1;//访问数组1的下标
        int j = num2.size()-1;//访问数组2的下标
        string str(i+j+2,'0');//初始化数组全为0
        for (;i>=0; i--)//遍历num1中的每个元素，和num2中的数字相乘
        {   j = num2.size()-1;//每次遍历时更新被乘数的下标
            for (;j>=0; j--)
            {
                int temp = (num1[i]-'0')*(num2[j]-'0')+(str[i+j+1]-'0');//计算当前的两数的乘积，并加上原本个位
                str[i+j+1] = temp%10+'0';//更新当前位
                str[i+j]+=temp/10;//this is tricky，前一个进行进位，当发生连续进位时，以字符形式进行存储，不着急进位
            }
        }
        for (int i = 0; i < str.size(); i++)
        {//处理掉前面多余的0
           if (str[i]!='0')
           {
                return str.substr(i);
           }
        }
        return "0";
    }
};
// @lc code=end

