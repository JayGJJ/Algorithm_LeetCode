/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution {
public://递归
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)return root;//如果当前节点为空直接返回
        if (key<root->val){//如果目标值比当前值小，对左子树进行递归
            root->left = deleteNode(root->left,key);
            return root;
        }
        if (key>root->val){//如果目标值比当前值大，对右子树进行递归
            root->right = deleteNode(root->right,key);
            return root;
        }
        if (key==root->val)//如果当前值为目标值
        {
            if (!root->left && !root->right)
            {//如果没有左右子树直接返回空
                return nullptr;
            }
            else if (!root->left)
            {//如果只存在右子树，直接返回右节点
                return root->right;
            }
            else if (!root->right)
            {//如果只存在左子树，直接返回左节点
                return root->left;
            }
            //左右子树同时存在
            //寻找到左子树中的最大节点，替换原节点
            TreeNode* lMax = root->left;
            while (lMax->right)lMax = lMax->right;
            //从左子树中移除所找到的最大节点
            root->left = deleteNode(root->left,lMax->val);
            //利用所找到的最大节点替换原节点
            lMax->right = root->right;
            lMax->left = root->left;
            return lMax;
        }
        return root;
    }
};
// @lc code=end

