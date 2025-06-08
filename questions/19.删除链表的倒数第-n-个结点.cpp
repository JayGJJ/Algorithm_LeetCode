// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem19.h"

using namespace std;
// @before-stub-for-debug-end



/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!n)return head;
        ListNode* hat = new ListNode(0,head);//给头结点一个帽子结点，以便对后续结点通用处理
        ListNode* fast = hat,*slow = hat;//快慢指针
        int i=0;//记录结点位置
        while(fast && i++<n)fast = fast->next;//快指针移动到第n个位置
        if(!fast)return head;//结点个数小于n，无法删除
        while(fast->next){
            fast = fast->next;
            slow  = slow->next;
        }//快指针移动到末尾，此时慢指针位于倒数第n个结点的前一个结点
        slow->next = slow->next->next;//删除第n个结点
        return hat->next;//返回头节点
    }
};
// @lc code=end

