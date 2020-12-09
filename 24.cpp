// 24. Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes. Only nodes itself may be changed.

//  

// Example 1:


// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]
#include <iostream>
#include <vector>

using namespace std;

/** 
  Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = head->next;
        ListNode* tmp = head;
        while(!(tmp==nullptr||tmp->next==nullptr)){
            ListNode* first = tmp;
            ListNode* second = tmp->next;
            first->next = tmp->next->next;
            second->next = first;
            tmp = tmp->next;
        }
        return res;
    }
};

void print(ListNode* head){
    ListNode* tmp = head;

    while(tmp!=nullptr){
        cout<<(tmp->val)<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}

ListNode* toList(vector<int>& data){
    ListNode *head = new ListNode(),*tmp;
    tmp = head;
    for(int d:data){
        ListNode *t = new ListNode(d);
        tmp->next = t;
        tmp = tmp->next;
    }
    return head->next;
}



int main(){
    vector<int> d = {1,2,3,4};
    ListNode* head = toList(d);
    // print(head);
    Solution s = Solution();
    ListNode* res =  s.swapPairs(head);
    print(res);
    return 0;
}