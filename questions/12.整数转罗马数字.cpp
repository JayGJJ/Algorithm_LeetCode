
/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int highest = 0,scale=0;//highest表示当前数字最高位，scale表示当前数字范围
        while(num){
            if(num>=1000)scale = 1000;
            else if(num>=100)scale = 100;
            else if(num>=10)scale = 10;
            else scale = 0;

            if(scale){//取得最高位
                highest = num/scale;
            }else{
                highest = num;
            }

            if(highest==9){
                if(num>100){ans+="CM";num-=900;}
                else if(num>10){ans+="XC";num-=90;}
                else{ans+="IX";num-=9;}
            }else if(highest==4){
                if(num>100){ans+="CD";num-=400;}
                else if(num>10){ans+="XL";num-=40;}
                else{ans+="IV",num-=4;}
            }else{
                if(highest>=5){
                    if(scale==100){ans+="D",num-=500;}
                    else if(scale==10){ans+="L",num-=50;}
                    else{ans+="V";num-=5;}
                }else{
                    if(scale==1000){ans+="M",num-=1000;}
                    else if(scale==100){ans+="C",num-=100;}
                    else if(scale==10){ans+="X",num-=10;}
                    else{ans+="I",num-=1;}
                }
            }
        }
        return ans;
    }
};
// @lc code=end

