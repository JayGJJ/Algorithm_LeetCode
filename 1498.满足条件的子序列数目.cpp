/*
 * @lc app=leetcode.cn id=1498 lang=cpp
 *
 * [1498] 满足条件的子序列数目
 */

// @lc code=start
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
    int mod = 1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//对原数组进行排序，便于查找可以组成子序列中的最大值和最小值
        int i = 0,j = 0;
        unsigned long long count = 0;//最终结果
        for (i = 0; i < nums.size(); i++)
        {//遍历每一个min，由于min<=target/2,因此大于时退出循环
            if (nums[i]>target/2)break;
            //子序列中最小值为num[i],则最大值小于target-nums[i]
            //以二分法找到子序列中小于目标值的最大值
            j = bs(nums,target-nums[i]);
            if (j!=-1)//如果存在最大值
            //满足条件的子序列个数为2^(j-i)
            //用快速幂求取后取余
                count = (count+mypow(j-i))%mod;
        }
        return count;
    }
    int bs(vector<int>& nums,int t){
        int low = 0,high = nums.size()-1,mid;
        while (low<=high)
        {
            mid = (low+high)/2;
            if (nums[mid]>t)
            {//如果当前数大于目标值则不满足条件，移动右指针
                high = mid-1;
            }else{
                if (mid==nums.size()-1||nums[mid+1]>t)
                {//如果当前数满足条件并且位于最后一个数或满足条件的最大数则返回
                    return mid;
                }else{
                    //若存在满足条件更大的数则移动左指针
                    low = mid+1;
                }
            }
        }
        //无满足条件的数
        return -1;
    }
    int mypow(int n){//快速幂算法
        long long s = 1,p = 2;//s为结果，2为底数
        while (n)
        {//如果指数不为0则循环继续
            if(n&1){//如果为奇数则乘一个底数(拆解出一个底数)，并将结果取模，防止溢出
                s*=p,s%=mod;
            }
            p *= p;//底数进行平方
            p %= mod;//进行取模，防止溢出
            n>>=1;//指数除以2
        }
        return s;
    }
};
// @lc code=end

