/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        //如果头节点为空或只存在一个节点，则直接返回
        if (!head||!head->next)return head;
        //为避免特殊处理头节点，增加哑节点指向头节点，返回dummy->next即可
        ListNode* dummy = new ListNode(0,head);//在堆中开辟空间，避免空间不足
        // ListNode* dummy = new ListNode;
        // dummy->next = head;
        ListNode* cur = dummy;//指向当前节点
        while (cur->next && cur->next->next)
        {//若存在下个节点和下下个节点
           if (cur->next->val==cur->next->next->val)
           {//若存在相同值的节点，则将cur移至下个出现不同值的节点
                int x = cur->next->val;
                while (cur->next && cur->next->val==x)
                {
                    cur->next = cur->next->next;
                }
           }else{//若此后两个节点不同，则将cur后移一个节点
                cur = cur->next;
           }
        }
        return dummy->next;//返回哑节点指向的头节点
    }
};
// @lc code=end

