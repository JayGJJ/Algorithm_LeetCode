/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = -1;
        int r = letters.size();
        while (l+1<r)
        {//不断移动左右指针，使双指针位于小于等于target和大于target的交界处
            int m = (l+r)/2;
            char ch = letters[m];
            if (ch<=target)
            {
                l = m;
            }else if (ch>target)
            {
                r = m;
            }
        }
        //若存在大于target的字符则返回
        if (r!=letters.size())
        {
            return letters[r];
        }
        return letters[0];
    }
};
// @lc code=end

