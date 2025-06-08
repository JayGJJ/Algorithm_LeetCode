/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if (!head)return;//链表为空直接返回
        ListNode* mid = middleNode(head);//获取链表的中点
        ListNode* secondList = reverseList(mid->next);//获得翻转后的后半链表
        mid->next = nullptr;//获得前半链表
        mergeList(head,secondList);//合并链表
    }
    //寻找链表中点
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;//设置快慢指针
        while (fast->next&&fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }//快指针到达链尾时，慢指针位置即为链表中点
        return slow;
    }
    //翻转链表
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;//前置节点
        ListNode* cur = head;//当前节点
        while (cur)
        {
            ListNode* temp = cur->next;//临时节点保存当前节点后的节点
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;//返回翻转后的链表头部
    }
    //合并链表
    void mergeList(ListNode* l1,ListNode* l2){
        ListNode* p1;
        ListNode* p2;
        while (l1 && l2)
        {//l2<=l1,当l2为空时，合并结束
            p1 = l1->next;
            p2 = l2->next;

            l1->next = l2;
            l1 = p1;

            l2->next = l1;
            l2 = p2;
        }
    } 
};
// @lc code=end

