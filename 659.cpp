// 659. Split Array into Consecutive Subsequences
// Given an array nums sorted in ascending order, return true if and only if you can split it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.

//  

// Example 1:

// Input: [1,2,3,3,4,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3
// 3, 4, 5
// Example 2:

// Input: [1,2,3,3,4,4,5,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3, 4, 5
// 3, 4, 5
// Example 3:

// Input: [1,2,3,4,4,5]
// Output: False

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        for(auto& x : nums){
            if(mp.find(x) == mp.end()){
                mp[x] = priority_queue<int,vector<int>,greater<int>>();
            }
            if(mp.find(x-1)!=mp.end()){
                int prevLength = mp[x-1].top();
                mp[x-1].pop();
                if(mp[x-1].empty()){
                    mp.erase(x-1);
                }
                mp[x].push(prevLength+1);
            }else{
                mp[x].push(1);
            }
            for(auto it = mp.begin();it!=mp.end();++it){
                priority_queue<int,vector<int>,greater<int>> queue = it->second;
                if(queue.top() < 3){
                    return false;
                }
            }
            return true;
        }    
               
    }

    bool isPossible2(vector<int>& nums) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        for (int& i :nums){
            map1[i]++;
        }
        for (int& x : nums){
            int cnt = map1[x];
            if(cnt>0){
                int preEndCnt = map2[x-1];
                if(preEndCnt>0){
                    map1[x]--;
                    map2[x-1]--;
                    map2[x]++;
                }else{
                    int cnt1 = map1[x+1];
                    int cnt2 = map1[x+2];
                    if(cnt1>0&&cnt2>0){
                        map1[x]--;
                        map1[x+1]--;
                        map1[x+2]--;
                        map2[x+2]++;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void print(vector<int> &arr){
        for(int i:arr){
            cout<<i;
        }
        cout<<endl;
    }
};

int main()
{

    Solution s = Solution();
    vector<int> nums = {1,2,3,3,4,4,5,5};
    bool res = s.isPossible2(nums);
    cout<<res<<endl;
    return 0;
}
