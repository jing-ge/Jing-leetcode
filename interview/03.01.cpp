// 面试题 03.01. Three in One LCCI

// Describe how you could use a single array to implement three stacks.

// You should implement push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum) methods. stackNum is the index of the stack. value is the value that pushed to the stack.

// The constructor requires a stackSize parameter, which represents the size of each stack.

// Example1:

//  Input: 
// ["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
// [[1], [0, 1], [0, 2], [0], [0], [0], [0]]
//  Output: 
// [null, null, null, 1, -1, -1, true]
// Explanation: When the stack is empty, `pop, peek` return -1. When the stack is full, `push` does nothing.
// Example2:

//  Input: 
// ["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
// [[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
//  Output: 
// [null, null, null, null, 2, 1, -1, -1]

#include <iostream>
#include <vector>

using namespace std;

class TripleInOne {
public:
    int *stack;
    int p[3];
    int stackSize;
    TripleInOne(int stackSize):stackSize(stackSize) {
        stack = new int[stackSize*3];
        p[0] = p[1] = p[2] = 0;
    }
    
    void push(int stackNum, int value) {
        if(p[stackNum]<stackSize)
            stack[stackSize*stackNum+p[stackNum]++] = value;
    }
    
    int pop(int stackNum) {
        if(p[stackNum]>0){
            return stack[stackSize*stackNum+(--p[stackNum])];
        }
        return -1;
    }
    
    int peek(int stackNum) {
        if(p[stackNum]>0)
            return stack[stackSize*stackNum+(p[stackNum]-1)];
        else
            return -1;
    }
    
    bool isEmpty(int stackNum) {
        return p[stackNum]==0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */

int main(){
    TripleInOne* obj = new TripleInOne(2);
    obj->push(0,1);
    obj->push(0,2);
    obj->push(0,3);

    int param_2 = obj->pop(0);
    int param_3 = obj->pop(0);
    int param_4 = obj->pop(0);
    int param_5 = obj->peek(0);
    bool param_6 = obj->isEmpty(0);
    return 0;
}