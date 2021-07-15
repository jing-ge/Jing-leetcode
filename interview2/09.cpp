// 剑指 Offer 09. 用两个栈实现队列
// 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

// 示例 1：

// 输入：
// ["CQueue","appendTail","deleteHead","deleteHead"]
// [[],[3],[],[]]
// 输出：[null,null,3,-1]
// 示例 2：

// 输入：
// ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
// [[],[],[5],[2],[],[]]
// 输出：[null,-1,null,null,5,2]
// 提示：

// 1 <= values <= 10000
// 最多会对 appendTail、deleteHead 进行 10000 次调用
// 通过次数205,787提交次数285,416

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            if(s1.empty())return -1;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int t = s2.top();
        s2.pop();
        return t;
    }
};

int main(){
    CQueue* obj = new CQueue();
    vector<int>data = {1,2,3};
    for(int i=0;i<data.size();i++){
        obj->appendTail(data[i]);
    }
    for(int i=0;i<data.size();i++){
        cout<<obj->deleteHead()<<endl;
    }
    return 0;
}