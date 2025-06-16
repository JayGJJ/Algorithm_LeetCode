/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream sst(s);
        string word;
        while(sst >> word);
        return word.size();
    }
};
// @lc code=end

