// 面试题 10.11. Peaks and Valleys LCCI
// In an array of integers, a "peak" is an element which is greater than or equal to the adjacent integers and a "valley" is an element which is less than or equal to the adjacent inte­gers. For example, in the array {5, 8, 4, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array of integers, sort the array into an alternating sequence of peaks and valleys.

// Example:

// Input: [5, 3, 1, 2, 3]
// Output: [5, 1, 3, 2, 3]
// Note:

// nums.length <= 10000

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &nums){
    for(int &i :nums){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(i%2){
                if(nums[i]<nums[i-1])swap(nums[i],nums[i-1]);
            }else{
                if(nums[i]>nums[i-1])swap(nums[i],nums[i-1]);
            }
        }
    }
};

int main(){
    vector<int> nums = {5, 3, 1, 2, 3};
    Solution s = Solution();
    s.wiggleSort(nums);
    print(nums);    
    return 0;
}