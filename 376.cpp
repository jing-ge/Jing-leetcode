// 376. Wiggle Subsequence
// A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

// Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

// Example 1:

// Input: [1,7,4,9,2,5]
// Output: 6
// Explanation: The entire sequence is a wiggle sequence.
// Example 2:

// Input: [1,17,5,10,13,15,10,5,16,8]
// Output: 7
// Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
// Example 3:

// Input: [1,2,3,4,5,6,7,8,9]
// Output: 2

#include <iostream>
#include <vector>

using namespace std;

class S{
public:
    vector<int> data;
    bool flag;
    void push(int x){
        if(data.size()>0&&(x==data[data.size()-1]))return;
        if (data.size()<2){
            data.push_back(x);
            if(data.size()==2){
                flag = data[1]<data[0];
            }
            return;
        }
        if(flag){
            if(x>data[data.size()-1]){      
                data.push_back(x);
                flag = !flag;
            }else{
                data.pop_back();
                data.push_back(x);
            }
        }else{
            if(x<data[data.size()-1]){
                data.push_back(x);
                flag = !flag;
            }else{
                data.pop_back();
                data.push_back(x);
            }
        }

        return;
    }
    int size(){
        return data.size();
    }
    int wiggleMaxLength2(vector<int>& nums){
        int n = nums.size();
        if(n<2){
            return n;
        }
        int predif = nums[1]-nums[0];
        int ret = predif!=0?2:1;
        for(int i = 2;i<n;i++){
            int dif = nums[i]-nums[i-1];
            if((dif>0&&predif<=0)||(dif<0&&predif>=0)){
                ret++;
                predif = dif;
            }
        }
        return ret;
    }
};

void print(vector<int>& nums){
    for(int i:nums){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        S s = S();
        for(int i:nums){
            s.push(i);
            print(s.data);
            cout<<s.flag<<endl;
            cout<<"-------"<<endl;
        }
        return s.size();
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums = {1,7,4,9,2,5};
    int res = s.wiggleMaxLength(nums);
    cout<<res<<endl;
    return 0;
}
