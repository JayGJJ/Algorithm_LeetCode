/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include <deque>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)return ret;//指针为空直接返回

        queue<TreeNode*> que;//利用队列层序遍历
        que.emplace(root); 
        bool flag = true;//设置标志位记录遍历顺序
        while (!que.empty())//队列还有元素则循环继续
        {
            deque<int> group;//使用双端队列控制输出顺序
            int n = que.size();//记录当前队列中元素个数，即为当前组元素个数
            for (int i = 0; i < n; i++)
            {
                auto head = que.front();
                que.pop();//移除节点
                if (flag)
                {//根据标志位判定顺序或者逆序插入
                    group.emplace_back(head->val);
                }else{
                    group.emplace_front(head->val);
                }
                //如果当前节点有左节点或右节点则加入队列
                if (head->left)que.emplace(head->left);
                if (head->right)que.emplace(head->right);
            }
            flag = !flag;//换行转换标志位
            ret.emplace_back(vector<int>(group.begin(),group.end()));//将当前数组加入结果集
        }
        return ret;
    }
};
// @lc code=end

