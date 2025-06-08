/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int,TreeNode*> hashmap;//记录每个节点的父结点
    unordered_map<int,bool> vis;//记录节点是否访问
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancestorNode(root);//构造父子节点映射
        hashmap[root->val] = nullptr;//头节点的头节点置为空，循环结束条件
        while (p)
        {
            vis[p->val] = true;//记录节点已经访问
            p = hashmap[p->val];//节点上移
        }
        while (q)
        {//从下往上遍历，遇到第一个被遍历的元素即为最近公共祖先
            if (vis[q->val])return q;
            q = hashmap[q->val];
        }
        return nullptr;
    }
    TreeNode* ancestorNode(TreeNode* &root){
        //利用递归构造父子节点映射
        if (root->left){
            hashmap[root->left->val] = root;
            ancestorNode(root->left);
        };
        if (root->right){
            hashmap[root->right->val] = root;
            ancestorNode(root->right);
        }
        return nullptr;   
    }
};
// @lc code=end

