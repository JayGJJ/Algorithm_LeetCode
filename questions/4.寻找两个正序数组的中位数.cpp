// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem4.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m>n)
        {//确保num1为最小数组
            swap(nums1,nums2);
            swap(n,m);
        }
        //分割线左边的元素总个数
        int totalLeft = (m+n+1)/2;
        //在num1[0,m]区间寻找合适的分割线
        int left = 0;
        int right = m;
        while (left<right)//循环至left==right则为正确分界线位置
        {
            int i = (left+right)/2;//num1中分界线左边的元素个数
            int j = totalLeft-i;//num2中分界线左边的元素个数
            if (nums1[i]<nums2[j-1])//num1分界线右边的元素小于num2分界线左边的元素则不符合，num1分界线需要右移
            {//下一轮搜索区间[i+1,m]
                left = i+1;
            }else{//下一轮搜索区间[0,right]
                right = i;
            }
        }   
        int i = left;//num1中正确分界线左边的元素个数
        int j = totalLeft-i;//num2中正确分界线左边的元素个数
        //找出数组中分界线左右第一个值
        //若分界线为0，则左值置为最小值，防止成为分界线左边最大值
        int num1Left = i==0?-__INT_MAX__-1:nums1[i-1];
        //若分界线为m，则左值置为最大值，防止成为分界线右边最小值
        int num1Right = i==m?__INT_MAX__:nums1[i];
        int num2Left = j==0?-__INT_MAX__-1:nums2[j-1];
        int num2Right = j==n?__INT_MAX__:nums2[j];
        if((m+n)%2==1){
            //元素总数为奇数则返回分界线左边最大值
            return max(num1Left,num2Left);
        }else{
            //元素总数为偶数则返回分界线左边最大值和右边最小值的平均值
            return (double)(max(num1Left,num2Left)+min(num1Right,num2Right))/2;
        }
    }
};
// @lc code=end

