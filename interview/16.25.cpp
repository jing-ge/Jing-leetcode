
// Design and build a "least recently used" cache, which evicts the least recently used item. The cache should map from keys to values (allowing you to insert and retrieve a value associ­ated with a particular key) and be initialized with a max size. When it is full, it should evict the least recently used item.

// You should implement following operations:  get and put.

// Get a value by key: get(key) - If key is in the cache, return the value, otherwise return -1.
// Write a key-value pair to the cache: put(key, value) - If the key is not in the cache, then write its value to the cache. Evict the least recently used item before writing if necessary.

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

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