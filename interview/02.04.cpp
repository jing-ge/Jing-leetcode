// 面试题 02.04. Partition List LCCI
// Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

// Example:

// Input: head = 3->5->8->5->10->2->1, x = 5
// Output: 3->1->2->10->5->5->8

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0),*l2 = new ListNode(0);
        ListNode *t1 = l1,*t2 = l2,*tmp = head;
        while (tmp!=nullptr)
        {
            ListNode*cur = tmp;
            tmp = tmp->next;
            cur->next = nullptr;
            if(cur->val<x){
                t1->next = cur;
                t1 = t1->next;
            }else{
                t2->next = cur;
                t2 = t2->next;
            }
        }
        t1->next = l2->next;

        return l1->next;
    }
};

int main(){
    vector<int> data = {3,5,8,5,10,2,1};
    int x = 5;
    ListNode* head = genList(data);
    print(head);
    Solution s = Solution();
    ListNode* newhead = s.partition(head,x);
    print(newhead);
    return 0;
}