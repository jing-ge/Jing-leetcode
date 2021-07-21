// 剑指 Offer 52. 两个链表的第一个公共节点
// 输入两个链表，找出它们的第一个公共节点。

// 如下面的两个链表：



// 在节点 c1 开始相交。

 

// 示例 1：



// 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
// 输出：Reference of the node with value = 8
// 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

// 示例 2：



// 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// 输出：Reference of the node with value = 2
// 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

// 示例 3：



// 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// 输出：null
// 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
// 解释：这两个链表不相交，因此返回 null。
 

// 注意：

// 如果两个链表没有交点，返回 null.
// 在返回结果后，两个链表仍须保持原有的结构。
// 可假定整个链表结构中没有循环。
// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
// 本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
// 通过次数139,397提交次数216,694

#include <iostream>
#include <vector>
#include <string>

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

ListNode* createList(vector<int> &nums){
    vector<ListNode*> tmp;
    for(int i:nums){
        tmp.push_back(new ListNode(i));
    }
    for(int i=1;i<nums.size();i++){
        tmp[i-1]->next = tmp[i];
    }
    return tmp[0];
}

class Solution {
public:
    int getListLen(ListNode* head){
        int res = 0;
        while (head!=nullptr)
        {
            head=head->next;
            res++;
        }
        return res;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLen(headA),lenB = getListLen(headB);
        ListNode* llong,*lshort;
        int lenlong = max(lenA,lenB),lenshort = min(lenA,lenB);
        if(lenA>lenB){
            llong = headA;
            lshort = headB;
        }else{
            llong = headB;
            lshort = headA;
        }
        for(int i=lenshort;i<lenlong;i++){
            llong = llong->next;
        }
        ListNode *res = nullptr;
        while (llong!=nullptr)
        {
            if(llong==lshort){
                res = llong;
                break;
            }
            llong = llong->next;
            lshort = lshort->next;
        }
        return res;
    }
};

int main(){
    vector<int> list1 = {4,1,8,4,5};
    vector<int> list2 = {5,0,1,8,4,5};
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(8);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(0);
    ListNode* node8 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node6->next = node7;
    node7->next = node8;
    node8->next = node3;
    Solution s;
    ListNode* res = s.getIntersectionNode(node1,node6);
    cout<<res->val<<endl;
    return 0;
}