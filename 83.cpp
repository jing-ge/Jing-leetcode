// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:


// Input: head = [1,1,2,3,3]
// Output: [1,2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.
// 通过次数208,377提交次数395,194
#include <iostream>
#include <vector>

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

void print(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}
class Solution {
public:
    ListNode* deleteDuplicates1(ListNode* head) {
        ListNode* tmp = head;
        while(tmp){
            while(tmp->next&&tmp->val==tmp->next->val){
                tmp->next = tmp->next->next; 
            }
            tmp = tmp->next;
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* tmp = head;
        while(tmp->next){
            if(tmp->val==tmp->next->val){
                tmp->next = tmp->next->next;
            }else{
                tmp = tmp->next;
            }
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
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