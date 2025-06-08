/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        char letter[] = {'a','e','i','o','u'};
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            int flag = 0;
            for (char ele:letter)
            {
                if (words[i][0]==ele)
                {
                    flag++;
                }
                if (words[i][words[i].size()-1]==ele)
                {
                    flag++;
                }
            }//当首位字符都存在于元音数组时，count++
            if (flag==2)count++;   
        }
        return count;
    }
};
// @lc code=end

