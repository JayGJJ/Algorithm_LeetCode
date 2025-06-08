/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> charmap;//利用hash表存储 以字符为键，字符串为值
        unordered_map<string,char> strmap;//存储字符串的对应关系
        istringstream is(s);//读取各个单词
        string str = "";//记录截取的子字符串
        int i = 0;//记录读取字符下标
        while (is>>str)//依次读取空格分隔的各个单词
        {
            if (i>=pattern.size())//当字符下标超出边界时，两数组长度不同,返回false
            {
                return false;
            }
            char ch = pattern[i];
            if ((charmap.count(ch)&&charmap[ch]!=str)||(strmap.count(str)&&strmap[str]!=ch))
            {//判断hash表中当前位置是否符合对应值，先判断是否有元素，防止访问出错
                return false;
            }
            else{//若两表中都无当前元素，则插入hash表
                charmap.insert(make_pair(ch,str));
                strmap.insert(make_pair(str,ch));
            }
            i++;//移动遍历字符下标位置
        }
        return i==pattern.size();//判断s遍历完成时,pattern是否也遍历完成
    }
};
// @lc code=end

