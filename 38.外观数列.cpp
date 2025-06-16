// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem38.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        int i = 1,count = 0;
        string str;
        string cands = "1";
        char last = 0;
        while(i<n){
            str = cands;
            cands.clear();
            count = 0;
            last = str[0];
            for(auto e : str){
                if(e == last)
                    count++;
                else{
                   cands += to_string(count);
                   cands += last;
                   count = 1;
                }
                last = e;
            }
            cands += to_string(count);
            cands += str[str.size()-1];
            i++;
        }
        return cands;
    }
};
// @lc code=end

