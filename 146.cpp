// 146. LRU Cache
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// Follow up:
// Could you do get and put in O(1) time complexity?

 

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
 

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 3000
// 0 <= value <= 104
// At most 3 * 104 calls will be made to get and put.
// 通过次数127,668提交次数247,610

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int keyv,int value):key(keyv),val(value),prev(nullptr),next(nullptr){

    }
};

class LRUCache {
public:
    int size;
    int cap;
    Node* head;
    Node* tail;
    map<int,Node*>mymap;
    LRUCache(int capacity) {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(mymap[key]==nullptr)return -1;
        Node *tmp = mymap[key];
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;

        tmp->next = head->next;
        head->next = tmp;
        tmp->next->prev = tmp;
        tmp->prev = head;
        return mymap[key]->val;
    }
    
    void put(int key, int value) {
        if(mymap[key]==nullptr){
            Node* tmp = new Node(key,value);
            if(size==cap){
                Node* t = tail->prev;
                t->prev->next = tail;
                tail->prev = t->prev;
                mymap.erase(t->key);
                // delete t;   
                size--;
            }
            tmp->next = head->next;
            head->next = tmp;
            tmp->next->prev = tmp;
            tmp->prev = head;
            size++;
            mymap[key] = tmp;
        }else{
            get(key);
            mymap[key]->val = value;
        }
    }
};

int main(){
    LRUCache cache = LRUCache(2);

    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
    return 0;
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cout<<cache.get(2)<<endl;       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cout<<cache.get(1)<<endl;       // 返回 -1 (未找到)
    cout<<cache.get(3)<<endl;       // 返回  3
    cout<<cache.get(4)<<endl;       // 返回  4
    return 0;
}