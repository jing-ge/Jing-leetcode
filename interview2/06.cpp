// 剑指 Offer 06. 从尾到头打印链表 LCOF
// English description is not available for the problem. Please switch to Chinese.

// 通过次数231,996提交次数308,748

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* tmp = head;
        while(tmp!=nullptr){
            res.push_back(tmp->val);
            tmp = tmp->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution s;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    vector<int> res = s.reversePrint(node1);
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}