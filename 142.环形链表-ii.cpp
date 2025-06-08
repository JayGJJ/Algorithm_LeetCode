/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
#include <cstddef>
  struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
    };
#include <unordered_map>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)//若链表无结点或只存在一个节点则无环
        {
            return nullptr;
        }
        unordered_map<ListNode*,int> hashmap;//存储结点是否经过
        ListNode* pre = head;//前结点
        ListNode* last = head->next;//后结点
        while (last->next)//若下个节点为空则无环
        {
            hashmap.insert(make_pair(pre,1));//将当前节点存入hash表
            pre = last;//当前节点后移
            last = last->next;//下节点后移
            if (hashmap.find(last)!=hashmap.end())
            {//若当前节点在hash表中存在，证明已经经过，有环
                return last;
            }
        }
        return nullptr;
    }
};
// @lc code=end

