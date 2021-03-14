// 705. Design HashSet
// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

// Example 1:

// Input
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// Output
// [null, null, null, true, false, null, true, null, false]

// Explanation
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // return True
// myHashSet.contains(3); // return False, (not found)
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // return True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // return False, (already removed)
 

// Constraints:

// 0 <= key <= 106
// At most 104 calls will be made to add, remove, and contains.
 

// Follow up: Could you solve the problem without using the built-in HashSet library?
// 通过次数50,799提交次数78,143

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyHashSet1 {
public:
    /** Initialize your data structure here. */
    vector<int> data;
    int n = 10000000;
    MyHashSet() {
        data = vector<int>(n,INT32_MIN);
    }
    
    void add(int key) {
        if(data[key%n]!=INT32_MIN)
            data[key%n] = key;
    }
    
    void remove(int key) {
        data[key%n] = INT32_MIN;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(data[key%n]!=INT32_MIN)
            return true;
        else 
            return false;
    }
};

class MyHashSet {
private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key){
        return key % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data = vector<int>(base);
    }
    
    void add(int key) {
        int h = hash(key);
        for(auto it = data[h].begin();it!=data[h].end();it++){
            if((*it)==key)return;
        }
        data[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it = data[h].begin();it!=data[h].end();it++){
            if((*it)==key){
                data[h].erase(it);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for(auto it = data[h].begin();it!=data[h].end();it++){
            if((*it)==key)return true;
        }
        return false;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */