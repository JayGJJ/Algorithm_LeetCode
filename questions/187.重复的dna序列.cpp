/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
#include <vector>
using namespace std;
#include <string>
#include <unordered_map>           
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hashmap;//以字串为键，出现次数为值
        vector<string> v;//存储结果
        int length = s.size()-9;//遍历到倒数第10个字符结束
        for (int i = 0; i < length; i++)
        {
            string str = s.substr(i,10);//截取当前位置开始的十个字符
            if (++hashmap[str]==2)//出现次数+1,当出现次数为2则加入结果集，并防止重复包含
            {
                v.emplace_back(str);
            }
        }
        return v;
    }
};
// @lc code=end

