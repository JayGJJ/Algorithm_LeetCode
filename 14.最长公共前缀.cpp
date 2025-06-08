/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
           string ans = "";
           int i = 0,minlen=strs[0].size();//工作指针,最小长度
           for(auto e: strs)minlen = min((int)e.size(),minlen);//记录最小长度
           while(i<minlen){
                for(int j=0;j<strs.size()-1;j++){
                    if(strs[j][i]!=strs[j+1][i])return ans;
                }
                ans += strs[0][i];
                i++;
           }
           return ans;
    }
};
// @lc code=end

