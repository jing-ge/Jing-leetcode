// 面试题 02.07. Intersection of Two Linked Lists LCCI
// Given two (singly) linked lists, determine if the two lists intersect. Return the inter­ secting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.

// Example 1:

// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
// Output: Reference of the node with value = 8
// Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
// Example 2:

// Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Reference of the node with value = 2
// Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
// Example 3:

// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: null
// Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
// Explanation: The two lists do not intersect, so return null.
// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getLen(headA);
        int l2 = getLen(headB);
        ListNode *list1 = headA,*list2 = headB;
        int i = 0;
        if(l1>l2){
            while(i<(l1-l2)){
                list1 = list1->next;
                i++;
            }
        }else if(l2>l1){
            while(i<(l2-l1)){
                list2 = list2->next;
                i++;
            }
        }
        while(list1!=list2){
            list1 = list1->next;
            list2 = list2->next;
        }
        return list1;
    }
    int getLen(ListNode *head){
        ListNode* tmp = head;
        int res = 0;
        while(tmp!=nullptr){
            res++;
            tmp = tmp->next;
        }
        return res;
    }
};

int main(){
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new  ListNode(1);
    ListNode *node3 = new  ListNode(8);
    ListNode *node4 = new  ListNode(4);
    ListNode *node5 = new  ListNode(5);

    ListNode *node6 = new  ListNode(5);
    ListNode *node7 = new  ListNode(0);
    ListNode *node8 = new  ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node6->next = node7;
    node7->next = node8;
    node8->next = node3;
    Solution s = Solution();
    ListNode *res = s.getIntersectionNode(node1,node6);
    cout<<res->val<<endl;
    return 0;
}