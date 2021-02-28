// 448. Find All Numbers Disappeared in an Array
// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.

// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [5,6]
// 通过次数88,271提交次数139,703

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	int n = nums.size();
    	for(int i=0;i<n;i++){
    		int x = (nums[i]-1)%n;
    		nums[x]+=n;
    	}
    	vector<int> res;
    	for(int i=0;i<n;i++){
    		if(nums[i]<=n)res.push_back(i+1);
    	}
    	return res;
    }
};

int main(){
	Solution s;
	vector<int> nums = {4,3,2,7,8,2,3,1};
	vector<int> res = s.findDisappearedNumbers(nums);
	for(int i:res){
		cout<<i<<",";
	}
	cout<<endl;
	return 0;
}