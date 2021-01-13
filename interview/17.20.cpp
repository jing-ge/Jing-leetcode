// 面试题 17.20. Continuous Median LCCI
// Numbers are randomly generated and passed to a method. Write a program to find and maintain the median value as new values are generated.

// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// For example,

// [2,3,4], the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:

// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
// Example:

// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>,greater<> > right;

    void resize(){
        if(left.size()>=right.size()+2){
            right.push(left.top());
            left.pop();
        }else if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    MedianFinder() {
        left.push(INT32_MIN);
        right.push(INT32_MAX);
    }
    
    void addNum(int num) {
        int lmax = left.top(),rmin = right.top();
        if(num<=lmax)left.push(num);
        else right.push(num);
        resize();
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (double)(left.top()+right.top())/2;
        }else{
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double r1 = obj->findMedian();
    obj->addNum(3);
    double r2 = obj->findMedian();
    return 0;
}