/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
#include <string>
#include <sstream>
using namespace std;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)return "#";//空节点在字符串中用#标记
        //利用先序遍历递归将当前值及子节点的值加入到字符串中，利用" "分割
        return to_string(root->val)+' '+serialize(root->left)+' '+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return rdeserialize(is);
    }
    TreeNode* rdeserialize(istringstream& is){
        //利用istringstream遇到空格停止截取的特性读取各节点值
        string cur;
        is>>cur;//当前结点值
        if (cur=="#")return nullptr;//置为空节点
        TreeNode* newNode = new TreeNode(stoi(cur));//建立当前节点
        //递归构造子节点
        newNode->left = rdeserialize(is);
        newNode->right = rdeserialize(is);
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

