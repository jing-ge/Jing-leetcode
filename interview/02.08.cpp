// 面试题 02.08. Linked List Cycle LCCI
// Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Example 2:

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Example 3:

// Input: head = [1], pos = -1
// Output: no cycle

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||head->next==nullptr)return nullptr;
        ListNode*fast = head,*slow = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)break;
        }
        if(fast!=slow)return nullptr;
        fast = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main(){
    Solution s = Solution();
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new  ListNode(2);
    ListNode *node3 = new  ListNode(0);
    ListNode *node4 = new  ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    ListNode*res = s.detectCycle(node1);
    cout<<res->val<<endl;
    return 0;
}