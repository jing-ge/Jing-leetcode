// 23. Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

//  

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
    
    ListNode* merge(vector<ListNode*> &lists,int l,int r){
        if (l==r)return lists[l];
        if (l>r)return nullptr;
        int mid = l + (r-l)/2;
        ListNode* lm = merge(lists,l,mid);
        ListNode* rm = merge(lists,mid+1,r);
        return merge2Lists(lm,rm);

    }

    ListNode* merge2Lists(ListNode* a,ListNode* b){
        if((!a)||(!b)) return a?a:b;
        ListNode head, *tail=&head,*pa = a,*pb = b;
        while(pa&&pb){
            if(pa->val<pb->val){
                tail->next = pa;
                pa = pa->next;
            }else{
                tail->next = pb;
                pb = pb->next;
            }
            tail = tail->next;
        }
        tail->next = pa?pa:pb; 
        return head.next;
    }
    vector<ListNode*> res;
    vector<ListNode*>& vec2node(const vector<vector<int>> data) {
        // vector<ListNode*> res;
        for(auto d:data){
            ListNode* head = new ListNode(),*t = head;
            for(int i:d){
                ListNode* tmp = new ListNode(i);
                t = tmp;
                t = t->next;
            }
            res.push_back(head);
        }
        return res;
    }
    
    void print(ListNode* lists){
        while(lists!=nullptr){
            cout<<lists->val<<"->";
            lists = lists->next;
        }
        cout<<endl;
    }
    void print(vector<ListNode*> lists){
        for(auto d:lists){
            while(d!=nullptr){
                cout<<d->val<<"->";
                d = d->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    vector<vector<int>> data = {{1,4,5},{1,3,4},{2,6}};
    Solution s = Solution();
    // ListNode* res = s.mergeKLists(s.vec2node(data));
    s.print(s.vec2node(data));
}