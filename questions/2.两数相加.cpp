/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr,*tail = nullptr;//创建首尾指针，记录链表和在尾部添加元素
        int add = 0;//记录进位
        while (l1||l2)//只要还存在元素则循环继续
        {
            int val1 = l1?l1->val:0;//如果当前指针为空，则赋予0
            int val2 = l2?l2->val:0;
            int sum = val1+val2+add;//两个相应的数字相加再加上进位
            if (!head)
            {
                head = tail = new ListNode(sum%10);//初始化首结点和尾结点
            }else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;//插入下个结点，并更新尾结点
            }
            add = sum/10;//记录进位
            if (l1)//结点不为空则后移
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (add>0)//判断链表遍历结束后是否存在进位
        {
            tail->next = new ListNode(add);
        }
        return head;
    }
};
// @lc code=end

