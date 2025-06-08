/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <vector>
using namespace std;
#include <string>
#include <unordered_map>
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v;//记存储各片段长度
        unordered_map<char,int> appear;//记录各字符出现次数
        int arr[27]={0};//记录当前元素是否访问过
        int len = 0;//记录当前片段长度
        for (int i = 0; i < s.size(); i++)
        {//利用hash表存储各字符出现次数
            appear[s[i]]++;
        }
        int sum = 0;//记录当前片段字符出现剩余次数
        for (int i = 0; i < s.size(); i++)
        {
            len++;//片段长度+1
            appear[s[i]]--;//对应字符数-1
            if (!arr[s[i]-'a'])//若此字符被首次访问
            {
                sum+=appear[s[i]];//加入出现次数
                arr[s[i]-'a'] = 1;//访问置1
            }else{
                sum--;//若不是首次访问，则sum-1
            }
            if (sum==0)
            {//若当前和为0，则可以成为一个片段，放入v，并更新len和sum为0
                v.push_back(len);
                len = 0;
                sum = 0;
            }
        }
        return v;
    }
};
// @lc code=end

