/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start

struct Node
{
    int val;//节点值
    Node* next;//指向下一个节点
    Node(int x,Node* p) : val(x),next(p){}//节点初始化方法
};

class MyLinkedList {
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new Node(0,nullptr);
    }//初始化链表头节点和长度设为0
    
    int get(int index) {
        if (index>=this->size||index<0)return -1;//验证下标是否有效
        int i = 0;
        Node* temp = this->head->next;
        while (i!=index)
        {
            temp = temp->next;
            i++;
        }
        return temp->val;//遍历到下标节点，返回值
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);//从头节点(下标为0)处插入
    }
    
    void addAtTail(int val) {
        addAtIndex(this->size,val);//从链尾(size)插入
    }
    
    void addAtIndex(int index, int val) {
        //下标选择插入
        if (index>size||index<0)
        {//验证下标是否有效
           return;
        }
        int i = 0;
        Node* temp = this->head;//从头节点开始,遍历到index-1下标处的节点
        while (i!=index)
        {
            temp = temp->next;
            i++;
        }
        Node* newNode = new Node(val,nullptr);//建立新节点
        newNode->next = temp->next;
        temp->next = newNode;//插入节点
        size++;
    }
    void deleteAtIndex(int index) {
        //验证下标是否有效
        if (index>=size||index<0||this->size==0)return;
        int i = 0;
        Node* temp = this->head;
        while (i!=index)
        {//从头节点开始,遍历到index-1下标处的节点
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        size--;//删除节点
    }
private:
    int size;//记录节点数
    Node* head;//头节点
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

