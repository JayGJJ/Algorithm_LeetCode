/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int cur=0,next=1;//工作指针
        int number = 0,t1,t2;
        while(s[cur]&&s[next]){
            t1 = getValue(s[cur]);//映射数字
            t2 = getValue(s[next]);
            if(t1<t2){//出现特殊情况
                number += t2-t1;
                cur+=2;next+=2;
            }else{
                number += t1;
                cur++;next++;
            }
        }
        if(s[cur]){
            number += getValue(s[cur]);
        }
        return number;
    }

    int getValue(char ch){
        switch(ch){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
};
// @lc code=end

