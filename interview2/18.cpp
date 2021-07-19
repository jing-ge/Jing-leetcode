// 剑指 Offer 18. 删除链表的节点
// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

// 返回删除后的链表的头节点。

// 注意：此题对比原题有改动

// 示例 1:

// 输入: head = [4,5,1,9], val = 5
// 输出: [4,1,9]
// 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
// 示例 2:

// 输入: head = [4,5,1,9], val = 1
// 输出: [4,5,9]
// 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 

// 说明：

// 题目保证链表中节点的值互不相同
// 若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
// 通过次数160,012提交次数269,835

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

void print(ListNode* head){
    while (head!=nullptr)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* sold = new ListNode(-1),*tmp = head,*pre = sold;
        sold->next = head;
        while (tmp!=nullptr)
        {
            if(tmp->val==val){
                pre->next = tmp->next;
                break;
            }
            tmp = tmp->next;
            pre = pre->next;
        }
        return sold->next;
    }
};

int main(){
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(9);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s;
    print(node1);
    ListNode* newhead =s.deleteNode(node1,5); 
    print(newhead);
    return 0;
}