/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public://中心拓展，从回文中心向两边拓展
    string longestPalindrome(string s) {
        int size = s.size();
        if (size<=1)return s;//当字符串长度小于等于1时，本身即是最长回文子串
        int begin = 0;//记录最长回文子串起始位置
        int end = 0;//记录最长回文子串结束位置
        int maxL = 0;//记录最长回文子串长度
        for (int i = 0; i < size-1; i++)//遍历到倒数第二个字符即可
        {
            int solo = searchStr(s,i,i+1);
            int doub = searchStr(s,i,i);//找出以当前节点为中心的回文子串长度
            maxL = max(max(solo,doub),maxL);//将以单节点和双节点以及原来最大长度作比较
            //aba i=1 maxL=3
            //abba i=1 maxl = 4
            if (maxL>end-begin+1)//若当前回文子串最长则更新起点和终点
            {
                begin = i-(maxL-1)/2;
                end = i+maxL/2;
            }
        }
        return s.substr(begin,maxL);
    }
private:
    int searchStr(string &str,int left,int right){
        while (left>=0&&right<str.size()&&str[left]==str[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
};
// @lc code=end

