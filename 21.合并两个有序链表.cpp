/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* hat = new ListNode();
        ListNode* p1=list1,*p2=list2,*temp = hat;
        while(p1 && p2){
            if(p1->val<p2->val){
                temp->next = p1;
                temp = temp->next;
                p1 = p1->next;
            }else{
                temp->next = p2;
                temp = temp->next;
                p2 = p2->next;
            }
        }
        while(p1){temp->next = p1;temp = temp->next;p1 = p1->next;}
        while(p2){temp->next = p2;temp = temp->next;p2 = p2->next;}
        return hat->next;
    }
};
// @lc code=end

