/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <unordered_map>
class Solution {
private://利用hash映射，快速在inorder中定位根节点
    unordered_map<int,int> hashmap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            hashmap.insert(make_pair(inorder[i],i));
        }//建立hash映射
        return creatTree(preorder,inorder,0,n-1,0,n-1);//递归建立树
    }
    TreeNode* creatTree(vector<int>& preorder, vector<int>& inorder,int prel,int prer,int inl,int inr){
        if (prel>prer)return nullptr;//坐下标大于右下标时，已无剩余元素，返回null
        
        int rootindex = hashmap[preorder[prel]];//首元素即为根元素
        TreeNode* root = new TreeNode(preorder[prel]);//创建根节点
        int leftnum = rootindex-inl;//记录当前根节点的左子树节点个数
        //递归构造左子树
        //prel+1即为下一个头节点，同时prel-gap即为左子树中节点最大下标，inl即为左子树最小节点下标，当前节点下标-1即为其最大下标
        root->left  = creatTree(preorder,inorder,prel+1,prel+leftnum,inl,rootindex-1);
        //递归构造右子树
        //prel+左子树节点个数+1即为右子树头节点，同时prer即为右子树中节点最大下标，当前节点下标+1即为右子树最小节点下标，inr即为其最大下标
        root->right = creatTree(preorder,inorder,prel+leftnum+1,prer,rootindex+1,inr);
        return root;
    }
};
// @lc code=end

