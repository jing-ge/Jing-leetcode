// 135. CandyThere are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Example 1:

// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.
// 通过次数37,793提交次数82,417

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& res){
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,0);
        for(int i=0;i<n;i++){
            if(i>0&&ratings[i-1]<ratings[i]){
                left[i] = left[i-1]+1;
            }else{
                left[i] = 1;
            }
        }
        int right = 0,ret = 0;
        for(int i=n-1;i>=0;i--){
            if(i<n-1 && ratings[i]>ratings[i+1]){
                right++;
            }else{
                right = 1;
            }
            ret += max(left[i],right);
        }
        return ret;
    }
};

int main(){
    vector<int> ratings = {1,0,2,3,4,8,9,2,1};
    Solution s = Solution();
    int res = s.candy(ratings);
    cout<<res<<endl;
    return 0;
}