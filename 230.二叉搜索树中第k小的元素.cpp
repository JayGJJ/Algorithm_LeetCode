/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
private:
    int min;//记录目标值
    int count;
public:
    int kthSmallest(TreeNode* root, int k) {
        seekElem(root,this->count,k);
        return min;
    }
    //利用BTS树的特性从小到大进行遍历，利用count计数
    void seekElem(TreeNode* &root,int &count,int k){
        if (!root)return;
        //中序遍历
        seekElem(root->left,count,k);
        if (++count == k){//到达第k个元素时，记录此时节点的值
            this->min = root->val;
            return;
        }
        seekElem(root->right,count,k);
        return;
    }
};
// @lc code=end

