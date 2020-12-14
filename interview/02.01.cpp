// 面试题 02.01. Remove Duplicate Node LCCI
// Write code to remove duplicates from an unsorted linked list.

// Example1:

//  Input: [1, 2, 3, 3, 2, 1]
//  Output: [1, 2, 3]
// Example2:

//  Input: [1, 1, 1, 1, 2]
//  Output: [1, 2]
// Note:

// The length of the list is within the range[0, 20000].
// The values of the list elements are within the range [0, 20000].
// Follow Up:

// How would you solve this problem if a temporary buffer is not allowed?


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> s = {head->val};
        ListNode*tmp = head;
        while (tmp->next!=nullptr)
        {
            ListNode* cur = tmp->next;
            if(!s.count(cur->val)){
                s.insert(cur->val);
                tmp = tmp->next;
            }else{
                tmp->next = cur->next;
            }
        }
        tmp->next = nullptr;        
        return head;
    }
    ListNode* createListNode(vector<int>data){
        ListNode* head = new ListNode(data[0]),*tmp = head;
        for(int i = 1;i<data.size();i++){
            tmp->next = new ListNode(data[i]);
            tmp = tmp->next;
        }
        return head;
    }
    void print(ListNode* head){
        ListNode* tmp = head;
        while (tmp!=nullptr)
        {
            cout<<tmp->val<<"->";
            tmp = tmp->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution s = Solution();
    ListNode* head =  s.createListNode({1, 2, 3, 3, 2, 1});
    ListNode* newhead = s.removeDuplicateNodes(head);
    s.print(newhead);
    return 0;
}