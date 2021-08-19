#include <iostream>

using namespace std;



struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = nullptr;
    }
};

void print(Node* head){
    Node* tmp = head;
    while(tmp!=nullptr){
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head){
    if(head==nullptr)return nullptr;
    Node *tmp = head,*prev = nullptr,*next;
    while (tmp!=nullptr)
    {
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    return prev;
    
}

int main(){
    Node* node1 = new Node(1);    
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    print(node1);
    Node* head = reverse(node1);
    print(head);
    return 0;
}