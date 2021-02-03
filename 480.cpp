// 480. Sliding Window Median
// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// Examples:
// [2,3,4] , the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

// Window position                Median
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
// Therefore, return the median sliding window as [1,-1,-1,3,5,6].

// Note:
// You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
// Answers within 10^-5 of the actual value will be accepted as correct.

// 通过次数10,926提交次数26,665

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iterator>

using namespace std;

class My{
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    int k;
    My(int _k){
        k = _k;
    }
    void insert(int x){
        if(small.empty()){
            small.push(x);
        }else{
            int t = small.top();
            if(x>t){
                big.push(x);
            }else{
                small.push(x);
            }
        }
        makebalance();
    }
    void erase(int x){
        if(x<=small.top()){
            priority_queue<int> q;
            while(small.size()){
                if(small.top()==x){
                    small.pop();
                    break;
                }else{
                    q.push(small.top());
                    small.pop();
                }
            }
            while(small.size()){
                q.push(small.top());
                small.pop();
            }
            small.swap(q);
        }else{
            priority_queue<int,vector<int>, greater<int>> q;
            while(big.size()){
                if(big.top()==x){
                    big.pop();
                    break;
                }else{
                    q.push(big.top());
                    big.pop();
                }
            }
            while(big.size()){
                q.push(big.top());
                big.pop();
            }
            big.swap(q);
        }
        makebalance();
    }
    void makebalance(){
        while(big.size()>small.size()){
            small.push(big.top());
            big.pop();
        }
        while(small.size()-1>big.size()){
            big.push(small.top());
            small.pop();
        }
    }
    double getmedia(){
        if(k&1){
            return small.top();
        }else{
            return ((long)small.top()+big.top())/2.0;
        }
    }
};

class Myheap{
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    unordered_map<int,int> map;
    int k;
    Myheap(int _k){
        k = _k;
    }
    template<typename T>
      void pure(T& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (map.count(num)) {
                --map[num];
                if (!map[num]) {
                    map.erase(num);
                }
                heap.pop();
            }
            else {
                break;
            }
        }
    }
    void insert(int x){
        if(small.empty()||x<=small.top()){
            small.push(x);
        }else{
            big.push(x);
        }
        makebalance();
        cout<<"s:"<<small.size()<<",b:"<<big.size()<<endl;
    }
    void erase(int x){
        map[x]++;
        if(x==small.top()){
            pure(small);
        }else if(x==big.top()){
            pure(big);
        }
        makebalance();
    }
    void makebalance(){
        if(big.size()>small.size()){
            small.push(big.top());
            big.pop();
            pure(big);
        }
        else if(small.size()>big.size()+1){
            big.push(small.top());
            small.pop();
            pure(small);
        }
    }
    double getmedia(){
        if(k&1){
            return small.top();
        }else{
            return ((double)small.top()+big.top())/2;
        }
    }
};


class DualHeap {
private:
    // 大根堆，维护较小的一半元素
    priority_queue<int> small;
    // 小根堆，维护较大的一半元素
    priority_queue<int, vector<int>, greater<int>> large;
    // 哈希表，记录「延迟删除」的元素，key 为元素，value 为需要删除的次数
    unordered_map<int, int> delayed;

    int k;
    // small 和 large 当前包含的元素个数，需要扣除被「延迟删除」的元素
    int smallSize, largeSize;

public:
    DualHeap(int _k): k(_k), smallSize(0), largeSize(0) {}

private:
    // 不断地弹出 heap 的堆顶元素，并且更新哈希表
    template<typename T>
    void prune(T& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                --delayed[num];
                if (!delayed[num]) {
                    delayed.erase(num);
                }
                heap.pop();
            }
            else {
                break;
            }
        }
    }

    // 调整 small 和 large 中的元素个数，使得二者的元素个数满足要求
    void makeBalance() {
        if (smallSize > largeSize + 1) {
            // small 比 large 元素多 2 个
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            // small 堆顶元素被移除，需要进行 prune
            prune(small);
        }
        else if (smallSize < largeSize) {
            // large 比 small 元素多 1 个
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            // large 堆顶元素被移除，需要进行 prune
            prune(large);
        }
    }

public:
    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        }
        else {
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }

    void erase(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        }
        else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        makeBalance();
    }

    double getmedia() {
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
    }
};

class Solution {
public:
    //简单粗暴，直接TLE
    vector<double> medianSlidingWindow1(vector<int>& nums, int k) {
        vector<double> res;
        for(int i=0;i<nums.size()-k+1;i++){
            vector<int> temp(nums.begin()+i,nums.begin()+i+k);
            sort(temp.begin(),temp.end());
            if(k&1){
                res.push_back(temp[k/2]);
            }else{
                res.push_back((temp[k/2-1]+temp[k/2])/2);
            }
        }
        return res;
    }
    //自定义数据结构
    vector<double> medianSlidingWindow2(vector<int>& nums, int k) {
        DualHeap my(k);
        for(int i=0;i<k;i++){
            my.insert(nums[i]);
        }
        vector<double> res;
        res.push_back(my.getmedia());
        for(int i=k;i<nums.size();i++){
            my.insert(nums[i]);
            my.erase(nums[i-k]);
            res.push_back(my.getmedia());
        }
        return res;
    }
    //使用multiset
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> my;
        for(int i=0;i<k;i++){
            my.insert(nums[i]);
        }
        vector<double> res;
        res.push_back(getmedia(k,my));
        for(int i=k;i<nums.size();i++){
            my.insert(nums[i]);
            my.erase(my.find(nums[i - k]));
            res.push_back(getmedia(k,my));
        }
        return res;
    }
    double getmedia(int k, multiset<int> & st){
        auto it = st.begin();
        advance(it, k/2);
        if(k&1){
            return *it;
        }else{
            cout<<*it<<endl;
            cout<<*prev(it,1)<<endl;
            return ((double)*it+*prev(it,1))/2;
        }
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,4,2,3};
    int k=4;
    vector<double>res = s.medianSlidingWindow(nums,k);
    for(auto t:res){
        cout<<t<<",";
    }
    cout<<endl;
    return 0;
}