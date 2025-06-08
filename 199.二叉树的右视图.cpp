/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;//创建结果集
        if (!root)return ret;//如果树为空直接返回
        queue<TreeNode*> que;//利用队列层次遍历
        que.emplace(root);//根节点入队
        while (!que.empty())//队列不为空循环继续
        {
            int n = que.size();//当前队列元素个数即为本层元素个数
            for (int i = 0; i < n; i++)
            {
                auto root = que.front();
                que.pop();//移除节点
                //若有左节点或右节点则入队
                if (root->left)que.push(root->left);
                if (root->right)que.push(root->right);
                if (i==n-1)ret.push_back(root->val);//本层最后一个元素即为最右侧元素，加入结果集                           
            }
        }
        return ret;
    }
};
// @lc code=end

