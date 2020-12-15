// 面试题 03.03. Stack of Plates LCCI
// Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack). Follow Up: Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

// You should delete the sub-stack when it becomes empty. pop, popAt should return -1 when there's no element to pop.

// Example1:

//  Input: 
// ["StackOfPlates", "push", "push", "popAt", "pop", "pop"]
// [[1], [1], [2], [1], [], []]
//  Output: 
// [null, null, null, 2, 1, -1]
//  Explanation: 
// Example2:

//  Input: 
// ["StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"]
// [[2], [1], [2], [3], [0], [0], [0]]
//  Output: 
// [null, null, null, null, 2, 1, 3]

#include <iostream>
#include <vector>

using namespace std;

class StackOfPlates {
public:
    vector<vector<int>> allstack;
    int size;
    StackOfPlates(int cap) {
        size = cap;
    }
    
    void push(int val) {
        if(size==0)return;
        if(allstack.size()==0||allstack[allstack.size()-1].size()==size){
            vector<int> tmp;
            tmp.push_back(val);
            allstack.push_back(tmp);
        }else{
            allstack[allstack.size()-1].push_back(val);
        }
    }
    int pop() {
        if(allstack.size()==0)return -1;
        int res = allstack[allstack.size()-1].back();
        allstack[allstack.size()-1].pop_back();
        if(allstack[allstack.size()-1].size()==0)
            allstack.pop_back();
        return res;

    }
    
    int popAt(int index) {
        if(index<0||index>=allstack.size()||allstack[index].size()<=0)return -1;
        int res = allstack[index].back();
        allstack[index].pop_back();
        if(allstack[index].size()==0){
            auto it = allstack.begin()+index;
            allstack.erase(it);
        }
        return res;
    }
};

int main(){
    StackOfPlates* obj = new StackOfPlates(1);
    obj->push(1);
    obj->push(2);
    int param_1 = obj->popAt(1);
    int param_2 = obj->pop();
    int param_3 = obj->pop();
    cout<<param_1<<endl;
    cout<<param_2<<endl;
    cout<<param_3<<endl;
    return 0;
}