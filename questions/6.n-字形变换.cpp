// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem6.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string> strs(numRows);
        string ans="";
        int i=0,var=1;
        for(auto e:s){
            strs[i] += e;
            i+=var;
            if(i==-1||i==numRows){
                var*=-1;
                i+= 2*var;
            }
        }
        for (auto e:strs)
        {
            ans+=e;
        }
        return ans;
    }
};
// @lc code=end

