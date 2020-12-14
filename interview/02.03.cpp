// 面试题 02.03. Delete Middle Node LCCI
// Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.

//  

// Example:

// Input: the node c from the linked list a->b->c->d->e->f
// Output: nothing is returned, but the new linked list looks like a->b->d->e->f

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* genList(vector<int>& data){
    ListNode *head = new ListNode(data[0]);
    ListNode *tmp = head;
    for(int i=1;i<data.size();i++){
        tmp->next = new ListNode(data[i]);
        tmp = tmp->next;
    }
    tmp->next = nullptr;
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

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(){
    vector<int> data = {4,5,1,9,8};
    ListNode* head = genList(data);
    print(head);
    Solution s = Solution();
    s.deleteNode(head->next->next);
    print(head);
    return 0;
}