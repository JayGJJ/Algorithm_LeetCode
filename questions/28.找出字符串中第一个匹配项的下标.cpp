/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> GetnextVal(string patternstr) {
    int n = patternstr.size(), j = -1;
    vector<int> nextval(n);
    nextval[0] = -1; //第一位固定
    for (int i = 1; i < n; i++) {
        while (j >= 0 && patternstr[i] != patternstr[j + 1]) j = nextval[j];
        if (patternstr[i] == patternstr[j + 1]) j++;
        if (j == -1 || patternstr[i + 1] != patternstr[j + 1])
            nextval[i] = j;
        else
            nextval[i] = nextval[j];
    }
    return nextval;
}

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    vector<int> nextval = GetnextVal(needle);
    for (int i = 0, j = 0; i < haystack.size(); i++) {
        while (j > 0 && haystack[i] != needle[j])
            j = nextval[j - 1] + 1; 
        if (haystack[i] == needle[j])
            j++;
        if (j == needle.size())
            return i - needle.size() + 1;
    }
    return -1;
}
};
// @lc code=end

