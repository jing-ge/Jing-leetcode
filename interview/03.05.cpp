// 面试题 03.05. Sort of Stacks LCCI
// Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty. When the stack is empty, peek should return -1.

// Example1:

//  Input: 
// ["SortedStack", "push", "push", "peek", "pop", "peek"]
// [[], [1], [2], [], [], []]
//  Output: 
// [null,null,null,1,null,2]
// Example2:

//  Input:  
// ["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
// [[], [], [], [1], [], []]
//  Output: 
// [null,null,null,null,null,true]
// Note:

// The total number of elements in the stack is within the range [0, 5000].


#include <iostream>
#include <stack>

using namespace std;

class SortedStack {
public:
    stack<int> s1;
    stack<int> s2;
    SortedStack() {

    }
    
    void push(int val) {
        if(s1.size()==0){
            s1.push(val);
            return;
        }
        while(s1.size()&&val>=s1.top()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop() {
        if(s1.size()==0)return;
        s1.pop();
    }
    
    int peek() {
        if(s1.size()==0)return -1;
        return s1.top();
    }
    
    bool isEmpty() {
        return s1.size()==0;
    }
};

class SortedStack2
{
public:
    stack<int> s1;
    stack<int> s2;
    SortedStack2();
    ~SortedStack2();
    void push(int val){
        while (!s2.empty()&&s2.top()>val)
        {
            s1.push(s2.top());
            s2.pop();
        }
        while (!s1.empty()&&s1.top()<val)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
    }
    void pop(){
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty())
            s1.pop();
    }
    int peek(){
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty())
            return s1.top();
        else return -1;
    }
    bool isEmpty(){
        return s1.empty()&&s2.empty();
    }
};



int main(){
    SortedStack* obj = new SortedStack();
    obj->push(1);
    obj->push(2);
    int param_3 = obj->peek();
    obj->pop();
    int param_5 = obj->peek();
    bool param_4 = obj->isEmpty();
    return 0;
}