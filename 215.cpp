// 215. Kth Largest Element in an Array
// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.


#include <iostream>
#include <vector>

using namespace std;


class Maxstack{
public:
    Maxstack(int n){
        p = 0;
        for(int i=0;i<n;i++){
            data.push_back(0);
        }
    }
    void push(int x){
        if(p>=data.size()){
            int i=data.size()-1;
            if(x<data[i])return;
            int t=-1;
            for(i--;i>=0;i--){
                if(x<data[i]&&x>=data[i+1]){
                    t = i;
                }
            }
            for(int j = data.size()-2;j>t;j--){
                data[j+1] = data[j];
            }
            data[t+1] = x;
        }else{
            if(p==0){
                data[p] = x;
                p++;
                return;
            }else{
                int t = -1;
                for(int i=0;i<p;i++){
                    if(x<data[i]&&x>=data[i+1]){
                        t = i;
                    }
                }
                for(int i=p;i>t;i--){
                    data[i+1] = data[i];
                }
                data[t+1] = x;
                p++;
            }
        }
    }
    int top(){
        return *(data.end()-1);
    }
    int size(){
        return data.size()-p-1;
    }
    void print(){
        for(int i=0;i<data.size();i++){
            cout<<data[i]<<",";
        }
        cout<<endl;
    }
    int p = 0;
    vector<int> data;
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Maxstack m = Maxstack(k);
        // m.print();

        for(int i:nums){
            m.push(i);
            // m.print();
        }
        return m.top();
    }
};


int main(){
    Solution s = Solution();
    vector<int> nums = {3,2,1,5,6,4,34,6,57,6,8,9887,9,34,2,34,3,546,5,6,5,75,8,79,4,34,23,4,324,23,4,324,32};
    int k = 4;
    int res = s.findKthLargest(nums,k);
    cout<<res<<endl;
    return 0;
}