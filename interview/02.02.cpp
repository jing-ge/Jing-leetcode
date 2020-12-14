// 面试题 02.02. Kth Node From End of List LCCI
// Implement an algorithm to find the kth to last element of a singly linked list. Return the value of the element.

// Note: This problem is slightly different from the original one in the book.

// Example:

// Input:  1->2->3->4->5 和 k = 2
// Output:  4
// Note:

// k is always valid.

#include <iostream>
#include <vector>

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
    int kthToLast(ListNode* head, int k) {
        ListNode*tmp = head;
        while(k>1){
            tmp = tmp->next;
            k--;
        }
        while (tmp->next!=nullptr)
        {
            tmp = tmp->next;
            head = head->next;
        }
        return head->val;
    }
    
    ListNode* genList(vector<int>& data){
        ListNode *head = new ListNode(data[0]);
        ListNode *tmp = head;
        for(int i=1;i<data.size();i++){
            tmp->next = new ListNode(data[i]);
            tmp = tmp->next;
        }
        return head;
    }
};


int main(){
    vector<int> data = {1,2,3,4,5};
    int k = 2;
    Solution s = Solution();
    ListNode* head =  s.genList(data);
    int res = s.kthToLast(head,k);
    cout<<res<<endl;
    return 0;
}