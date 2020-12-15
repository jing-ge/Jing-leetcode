// 面试题 03.02. Min Stack LCCI
// How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop and min should all operate in 0(1) time.

// Example:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> return -3.
// minStack.pop();
// minStack.top();      --> return 0.
// minStack.getMin();   --> return -2.


#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> min;
    MinStack() {

    }
    
    void push(int x) {
        if(stack.size()==0){
            stack.push_back(x);
            min.push_back(x);
        }else{
            stack.push_back(x);
            if(x<min[min.size()-1])
                min.push_back(x);
            else
                min.push_back(min[min.size()-1]);
        }
    }
    
    void pop() {
        if(stack.size()<=0)return;
        stack.pop_back();
        min.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
};


int main(){
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();
    minStack.pop();
    minStack.top();   
    minStack.getMin(); 
    return 0;
}