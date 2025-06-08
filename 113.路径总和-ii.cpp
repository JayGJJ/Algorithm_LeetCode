/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ret;//结果集
    vector<int> path;//存储每一条路径
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);//递归调用
        return ret;
    }
    void dfs(TreeNode* root, int targetSum){
        if (!root)return;//遇到空节点返回

        path.emplace_back(root->val);//当前节点加入路径
        targetSum -= root->val;//子树的节点和
        //当子树的节点和为0，且无子节点时，到达当前的叶子节点的路径和为targetsum，加入结果集
        if (targetSum==0 && !root->left && !root->right)ret.emplace_back(path);
        dfs(root->left,targetSum);//遍历左子树
        dfs(root->right,targetSum);//遍历右子树
        path.pop_back();//字数遍历完毕后移除当前节点，避免影响后续路径
    }
};
// @lc code=end

