/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
using namespace std;
// #include <queue>
class Solution {
public://时间复杂度O(nlogn) 空间复杂度O(n)
    //节点下沉
    void heapDown(vector<int>& nums,int i,int heapSize){
        int l = 2*i+1,r = 2*i+2,largest = i;//记录左右孩子结点和最大节点
        //当前节点依次和左右孩子结点比较，记录最大的节点
        if (l<heapSize&&nums[largest]<nums[l])largest = l;
        if (r<heapSize&&nums[largest]<nums[r])largest = r;
        if (largest!=i)
        {//若当前节点不为最大节点，则将其与最大节点进行交换，交换后递归下沉
            swap(nums[largest],nums[i]);
            heapDown(nums,largest,heapSize);
        }
    }
    void builtHeap(vector<int>& nums,int heapSize){
        for (int i = heapSize/2-1; i >=0 ; i--)
        {//构建大根堆,从最后一个非叶子节点size/2-1开始向前遍历，依次对每个结点进行下沉
            heapDown(nums,i,heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        builtHeap(nums,size);//构建大根堆
        for (int i = 0; i < k-1; i++)
        {//进行k-1次操作，栈顶元素即为第k个最大的元素
            swap(nums[0],nums[size-1]);//去除头节点即交换头尾结点
            --size;//减小取值范围，限制访问
            heapDown(nums,0,size);//对新的头节点进行下沉
        }
        return nums[0];
    }
};
// @lc code=end
// priority_queue<int,vector<int>,greater<int>> que;
        // for (auto ele : nums)
        // {
        //     if (que.size()==k&&que.top()>=ele)continue;
        //     if (que.size()==k)que.pop();
        //     que.push(ele);
        // }

