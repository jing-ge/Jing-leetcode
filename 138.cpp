// 138. Copy List with Random Pointer
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

 

// Example 1:


// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:


// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:



// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]
// Example 4:

// Input: head = []
// Output: []
// Explanation: The given linked list is empty (null pointer), so return null.
 

// Constraints:

// 0 <= n <= 1000
// -10000 <= Node.val <= 10000
// Node.random is null or is pointing to some node in the linked list.
// 通过次数99,130提交次数152,205

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        int i = 0;
        unordered_map<Node*,int> nodemap;
        vector<Node*> vec;
        Node* tmp = head;
        while (tmp!=nullptr)
        {
           Node* t = new Node(tmp->val);
           vec.push_back(t);
           nodemap[tmp] = i;
           i++;
           tmp = tmp->next;
        }
        vec.push_back(nullptr);
        nodemap[nullptr] = i;
        tmp = head;
        i = 0;
        for(int i=1;i<vec.size();i++){
            vec[i-1]->next = vec[i];
        }
        while (tmp!=nullptr)
        {
            vec[i]->random = vec[nodemap[tmp->random]];
            tmp = tmp->next;
            i++;
        }
        return vec[0];
    }
};
void print(Node*head){
    Node* tmp = head;
    while(head!=nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
    while (tmp!=nullptr)
    {   if(tmp->random!=nullptr)
        cout<<tmp->random->val<<";";
        else cout<<"nullptr;";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main(){
    Solution s;
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node1->random = nullptr;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;
    Node* head = s.copyRandomList(node1);
    print(head);
    return 0;
}