/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
private:
    vector<int> arr;//利用数组记录树中的元素，便于访问
    int index;//维护当前访问的元素下标
    //利用中序遍历构建数组
    void inOrder(TreeNode* &root,vector<int> &v){
        if (!root)return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    //构建数组
    void creatArr(TreeNode* &root){
        inOrder(root,this->arr);
    }
public:
    BSTIterator(TreeNode* root) {
        //初始化时根据给出的根节点构建数组，并将next置为0
        creatArr(root);
        this->index = 0;
    }
    
    int next() {
        //返回下一个元素(即为当前数组中index所在位置元素)
        return arr[this->index++];
    }
    
    bool hasNext() {
        //index未到达数组尾部则有下一个元素
        return index<arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

