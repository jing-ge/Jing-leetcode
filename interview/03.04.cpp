// 面试题 03.04. Implement Queue using Stacks LCCI
// Implement a MyQueue class which implements a queue using two stacks.

//  
// Example:

// MyQueue queue = new MyQueue();

// queue.push(1);
// queue.push(2);
// queue.peek();  // return 1
// queue.pop();   // return 1
// queue.empty(); // return false
//  

// Notes:

// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s1.size()==0&&s2.size()==0)return -1;
        if(s2.size()==0){
            while(s1.size()>0){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(s1.size()==0&&s2.size()==0)return -1;
        if(s2.size()==0){
            while(s1.size()>0){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.size()+s2.size())==0;
    }
};

int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(1);
    int param_3 = obj->peek();
    int param_2 = obj->pop();
    bool param_4 = obj->empty();
    return 0;
}