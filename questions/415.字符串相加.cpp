/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size()-1;//记录字符1位置，初始为第1位
        int size2 = num2.size()-1;//记录字符2位置，初始为第1位
        int add = 0;//用于记录是否有进位
        string str = "";//存储结果
        int ch1 = 0;//字符串1的字符
        int ch2 = 0;//字符串2的字符
        while (size1>=0 || size2>=0 || add ==1)//只要其中有一个字符没有遍历到结尾则循环继续
        {                                 //特殊情况:当两个字符串都已经遍历到结尾，但进位为1时循环继续
            ch1 = size1 < 0 ?0:num1[size1]-'0';//如果当前位置超出索引下线，置为0，负责为当前字符
            ch2 = size2 < 0 ?0:num2[size2]-'0';
            int plus = ch1 + ch2 + add;//将字符转化为int进行相加,并加上进位
            add = plus/10; //如果plus>=10，进位+1 否则进位 置为0
            str+=(char)plus%10+'0';//将字符进行拼接
            size1--;
            size2--;
        }
        reverse(str.begin(),str.end());//将字符逆置
        return str;
    }
};
// @lc code=end