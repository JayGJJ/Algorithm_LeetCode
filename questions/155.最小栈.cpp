/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
using namespace std;
class MinStack {
public:
    MinStack() {
        s = new stack<int>;
        mins = new stack<int>;
        mins->push(__INT_MAX__);//在最小栈中加入int最大值，作为栈中无元素标志
    }
    
    void push(int val) {
        s->push(val);//往原栈中添加元素
        if (val<=mins->top())
        {//如果当前元素是最小元素，则加入最小栈中
            mins->push(val);
        }
    }
    
    void pop() {
        if (mins->top()==s->top())
        {//移除元素时检查当前元素是否为最小值，如果是，最小栈同样移除元素
            mins->pop();
        }
        s->pop();
    }
    
    int top() {
        return s->top();//返回栈顶元素
    }
    
    int getMin() {//返回最小元素，即最小栈栈顶元素
        return mins->top();
    }
private:
    stack<int>* s;
    stack<int>* mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

