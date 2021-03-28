// 61. Rotate List
// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109
// 通过次数152,503提交次数365,682

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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)return head;
        ListNode* tmp = head;
        int len = 1;
        while(tmp->next!=nullptr){
            len++;
            tmp = tmp->next;
        }
        int count = len - k%len;
        if(count==len)return head;
        tmp->next = head;
        while(count--){
            tmp = tmp->next;
        }
        ListNode* res = tmp->next;
        tmp->next = nullptr;
        return res;
    }
};

void print(ListNode* root){
    ListNode* tmp = root;
    while(tmp!=nullptr){
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(node1);
    Solution s;
    ListNode* res = s.rotateRight(node1,2);
    print(res);
    return 0;
}