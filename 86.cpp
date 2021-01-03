// 86. Partition List
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5
// 通过次数78,249提交次数126,329

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode* tmp = head,*s = small,*b = big; 
        while(tmp!=nullptr){
            if(tmp->val<x){
                s->next = tmp;
                s = s->next;
            }else{
                b->next = tmp;
                b = b->next;
            }
            tmp = tmp->next;
        }
        s->next = big->next;
        b->next = nullptr;
        return small->next;
    }
};

void print(ListNode* head){
    ListNode*tmp = head;
    while (tmp!=nullptr)
    {
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main(){
    Solution s = Solution();
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    print(node1);
    ListNode*res =  s.partition(node1,3);
    print(res);
    return 0;
}