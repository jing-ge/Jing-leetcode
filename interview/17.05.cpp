// 面试题 17.05. Find Longest Subarray LCCI
// Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers.

// Return the subarray. If there are more than one answer, return the one which has the smallest index of its left endpoint. If there is no answer, return an empty arrary.

// Example 1:

// Input: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]

// Output: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
// Example 2:

// Input: ["A","A"]

// Output: []
// Note:

// array.length <= 100000
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<int> data;
        for(string &s:array){
            if(s[0]>='0'&&s[0]<='9'){
                data.push_back(0);
            }else{
                data.push_back(1);
            }
        }
        vector<int> idxs = helper(data);
        cout<<idxs[0]<<endl;
        cout<<idxs[1]<<endl;
        return vector<string>(array.begin()+idxs[0],array.begin()+idxs[1]);
    }
    vector<int> helper(vector<int>& nums) {
        unordered_map<int,int> map;
        map[0]=-1;
        int maxlength = 0;
        int sum = 0;
        int start=0,end=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i]==0?-1:1;
            if(map.find(sum)!=map.end()){
                int t = max(maxlength,i-map[sum]);
                if(t>maxlength){
                    maxlength =t;
                    start = map[sum];
                    end = i;
                }
            }else{
                map[sum] = i;
            }
        }
        return {start+1,end+1};
    }
};

int main(){
    // vector<string> array = {"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    vector<string> array = {"A","A"};
    Solution s = Solution();
    vector<string> res = s.findLongestSubarray(array);
    for(string&ss:res){
        cout<<ss<<",";
    }
    cout<<endl;
    return 0;
}