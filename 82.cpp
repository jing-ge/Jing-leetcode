// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.
// 通过次数98,066提交次数192,234

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nhead = new ListNode(-1),*ntmp = nhead;
        nhead->next = head;
        while(ntmp->next&&ntmp->next->next){
           if(ntmp->next->val==ntmp->next->next->val){
               int x = ntmp->next->val;
               while(ntmp->next&&ntmp->next->val==x){
                   ntmp->next = ntmp->next->next;
               }
           }else{
               ntmp = ntmp -> next;
           }
        }
        return nhead->next;
    }
};

int main(){
    Solution s;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(node1);
    ListNode* res = s.deleteDuplicates(node1);
    print(res);
    return 0;
}