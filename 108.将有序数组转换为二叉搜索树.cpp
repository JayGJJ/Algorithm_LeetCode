/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);//采用递归方法，传入左下标和右下标
    }
    TreeNode* helper(vector<int>& nums,int left,int right){
        if (left>right)return nullptr;//当左数大于右数，证明当前已无剩余节点，返回空
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);//数组中间位置做根节点
        root->left = helper(nums,left,mid-1);//左边部分归左节点，继续递归
        root->right = helper(nums,mid+1,right);//右边部分归右节点，继续递归
        return root;//返回根节点
    }
};
// @lc code=end

