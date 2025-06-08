/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA||!headB)
        {//若任一头节点为空，则无交点直接返回
            return nullptr;
        }
        ListNode* markA = headA;
        ListNode* markB = headB;//使用节点副本验证是否有交点
        int lengthA = 1;
        int lengthB = 1;//初始化链表长度为1
        while (markA->next)
        {//找出尾节点，并记录链表长度
            markA = markA->next;
            lengthA++;
        }
        while (markB->next)
        {
            markB = markB->next;
            lengthB++;
        }
        if (markA!=markB)return nullptr;//若尾节点不相等则无交点直接返回
        if (lengthA>lengthB)
        {//否则将长链表的起始节点向后移长度差个单位
         //使两个节点同时移动时能在交点处相遇
            for (int i = 0; i < lengthA-lengthB; i++)
            {
                headA = headA->next;
            }           
        }else{
            for (int i = 0; i < lengthB-lengthA; i++)
            {
                headB = headB->next;
            }
        }
        if (headA==headB)
        {//若起始节点相等则不用移动，直接返回当前节点
            return headA;
        }
        while (headA->next&&headB->next)
        {//将节点A、B移动至相交节点
            headA = headA->next;
            headB = headB->next;
            if (headA==headB)
            {
               return headA;
            }
        }
        return nullptr;
    }
};
// @lc code=end

