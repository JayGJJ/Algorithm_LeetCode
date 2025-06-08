// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
#include <stack>
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)return head;//判断头节点是否为空      
        ListNode* dummy = new ListNode(0,head);//创建哑节点，防止头节点特殊处理
        ListNode* cur = dummy;//记录当前节点
        ListNode* p = dummy;//将节点依次加入栈中
        ListNode* nextGroup = nullptr;//记录下一组的第一个节点
        stack<ListNode*> s;//利用栈先进后出的特点翻转链表
        while (1)
        {
            for (int i = k-1; i > 0; i--)
            {//依次将节点加入栈中
                if (p->next==nullptr)
                {//如果剩余节点数小于要翻转的节点数，则跳出循环
                    break;
                }
                s.emplace(p->next);
                p = p->next;
            }
            p = p->next;
            if (!p)
            {//如果剩余节点数小于要翻转的节点数，则跳出循环
                break;
            }
            cur->next = p;//将当前节点链接至翻转后的第一个节点
            nextGroup = p->next;//记录下一组的第一个节点
            while (s.size()!=0)
            {//从栈中弹出节点，翻转链表
                p->next = s.top();
                s.pop();
                p = p->next;
            }
            p->next = nextGroup;//翻转后的链表的最后一个节点链接至下一组的第一个节点
            cur = p;//当前节点后移k位，进入下次循环
        }
        return dummy->next;//返回翻转后的头节点
    }
};
// @lc code=end

