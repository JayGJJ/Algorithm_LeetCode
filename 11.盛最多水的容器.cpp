/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int lheight=0,rheight=height.size()-1;//容器左右边的高度
        while(lheight<rheight){
            ans = max(ans,(rheight-lheight)*min(height[lheight],height[rheight]));//当前容器容积
            //容器的容积取决于最短的那条边，因此试着移动短边进行比较
            if(height[lheight]<height[rheight]){
                lheight++;
            }else if(height[lheight]>height[rheight]){
                rheight--;
            }else{
                lheight++;rheight--;
            }
        }
        return ans;
    }
};
// @lc code=end

