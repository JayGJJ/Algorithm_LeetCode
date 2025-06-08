/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
using namespace std;
#include <string>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> hashmap;//以排序后字符串为键，下标为值
        vector<vector<string>> ret;//存储结果分组
        for (int i = 0; i < strs.size(); i++)
        {
            string stt = strs[i];
            sort(stt.begin(),stt.end());//对当前字符进行排序，
            hashmap[stt].push_back(i);//将其下标加入到对应组
        }
        for (auto s:hashmap)
        {
            vector<string> v;//存储一组字符
            for (int i: s.second)
            {
                v.emplace_back(strs[i]);//将利用排序后相同字符存储的下标，将异位词加入分组
            }
            ret.emplace_back(v);
        }
        return ret;
    }
};
// @lc code=end

