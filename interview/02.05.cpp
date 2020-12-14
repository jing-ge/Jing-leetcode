// 面试题 02.05. Sum Lists LCCI
// You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

//  

// Example:

// Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
// Output: 2 -> 1 -> 9. That is, 912.
// Follow Up: Suppose the digits are stored in forward order. Repeat the above problem.

// Example:

// Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
// Output: 9 -> 1 -> 2. That is, 912.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt = 0;
        vector<int>data;
        while(l1!=nullptr||l2!=nullptr){
            int v1 = 0,v2 = 0;
            v1 = l1==nullptr?0:l1->val;
            v2 = l2==nullptr?0:l2->val;
            int res = 0;
            if(v1+v2+cnt>=10){
                res = v1+v2+cnt-10;
                cnt = 1;
            }else{
                res = v1+v2+cnt;
                cnt = 0;
            }
            data.push_back(res);
            if(l1!=nullptr)
                l1 = l1->next;
            if(l2!=nullptr)
                l2 = l2->next;
        }
        if(cnt==1)data.push_back(cnt);
        return genList(data);
    }
};

int main(){
    vector<int> d1 = {5},d2 = {5};
    ListNode* l1 = genList(d1),*l2 = genList(d2);
    Solution s = Solution();
    ListNode*res = s.addTwoNumbers(l1,l2);
    print(res);
    return 0;
}