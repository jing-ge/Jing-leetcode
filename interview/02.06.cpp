// 面试题 02.06. Palindrome Linked List LCCI
// Implement a function to check if a linked list is a palindrome.

// Example 1:

// Input:  1->2
// Output:  false 
// Example 2:

// Input:  1->2->2->1
// Output:  true 

#include <iostream>
#include <vector>
#include <stack>

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome1(ListNode* head) {
        stack<int> s;
        ListNode*tmp = head;
        while(tmp!=nullptr){
            s.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp!=nullptr){
            if(tmp->val!=s.top())return false;
            s.pop();
            tmp = tmp->next;
        }
        return true;
    }
    bool isPalindrome2(ListNode* head){
        ListNode*fast = head,*slow = head;
        while (fast!=nullptr&&fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast!=nullptr)slow = slow->next;
        fast = head;
        slow = reverse(slow);
        while(slow!=nullptr){
            if(fast->val!=slow->val)return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head!=nullptr){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* tmp;
    bool isPalindrome(ListNode* head){
        tmp = head;
        return check(head);
    }
    bool check(ListNode* head){
        if(head==nullptr)return true;
        bool res = check(head->next)&&(tmp->val==head->val);
        // bool res = check(head->next);
        tmp = tmp->next;
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<int> data = {1,2,2,1};
    ListNode* head = genList(data);
    bool res = s.isPalindrome(head);
    cout<<res<<endl;
    return 0;
}