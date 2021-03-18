// 92. Reverse Linked List II
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
 

// Follow up: Could you do it in one pass?


#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *head){
    while(head!=nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *pseudohead = new ListNode(-1);
        pseudohead->next = head;
        ListNode *pre = pseudohead;
        for(int i=1;i<left;i++){
            pre = pre->next;
        }
        ListNode *cur = pre->next,*next = nullptr;
        for(int i=left;i<right;i++){
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return pseudohead->next;
    }
};

int main(){
    ListNode *node1 = new ListNode(1); 
    ListNode *node2 = new ListNode(2); 
    ListNode *node3 = new ListNode(3); 
    ListNode *node4 = new ListNode(4); 
    ListNode *node5 = new ListNode(5);
    node1->next = node2; 
    node2->next = node3; 
    node3->next = node4; 
    node4->next = node5; 
    print(node1);
    Solution s;
    int left = 2,right = 4;
    ListNode *head = s.reverseBetween(node1,left,right);
    print(head);
}