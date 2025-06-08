/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;//如果节点为空或只存在一个节点则不用交换
        ListNode* dummy = new ListNode(0,head);//创建哑节点防止头节点特殊处理
        ListNode* cur = dummy;//当前节点
        ListNode* p;//记录调换节点，防止访问位置丢失
        while (cur->next && cur->next->next)
        {//只要仍存在两个后续节点，则需要调换
            p = cur->next->next;//记录第二个节点
            cur->next->next = p->next;//第一个节点指向第二个节点的下个节点
            p->next = cur->next;//第二个节点指向第一个节点
            cur->next = p;//当前节点指向第二个节点
            cur = p->next;//当前节点后移至更新后的最后一个节点
        }
        return dummy->next;//返回哑节点指向的头节点
    }
};
// @lc code=end

