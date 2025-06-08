/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <string>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <vector>
class Solution {
public://时间复杂度有O(n+klogk) 空间复杂度有O(n+k)
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for (auto &ele:s)map[ele]++;//记录各字符出现次数
        vector<pair<char,int>> v;
        for (auto &ele:map)
        {
            v.emplace_back(ele);
        }//放入vector容器按照出现频率进行降序排序
        sort(v.begin(),v.end(),//使用了lambda匿名函数指定排序规则
        [](const pair<char,int> &a,const pair<char,int> &b){return a.second>b.second;});
        string newStr;
        for (auto &ele:v)
        {
            for (int i = 0; i < ele.second; i++)
            {//按照字符出现的次数，将各字符衔接
                newStr+=ele.first;
            } 
        }
        return newStr;//返回结果
    }
};
// @lc code=end

