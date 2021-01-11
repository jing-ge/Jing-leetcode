// 面试题 17.18. Shortest Supersequence LCCI
// You are given two arrays, one shorter (with all distinct elements) and one longer. Find the shortest subarray in the longer array that contains all the elements in the shorter array. The items can appear in any order.

// Return the indexes of the leftmost and the rightmost elements of the array. If there are more than one answer, return the one that has the smallest left index. If there is no answer, return an empty array.

// Example 1:

// Input:
// big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7]
// small = [1,5,9]
// Output: [7,10]
// Example 2:

// Input:
// big = [1,2,3]
// small = [4]
// Output: []
// Note:

// big.length <= 100000
// 1 <= small.length <= 100000
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void print(vector<int> & res){
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_set<int> smallset(small.begin(),small.end());
        if(big.size()<small.size())return {};
        unordered_set<int> tmp(big.begin(),big.begin()+small.size());
        int start = 0,end = small.size()-1;
        int res = big.size();
        int minstart=-1,minend=-1;
        while(start<big.size()&&end<big.size()&&start<=end){
            // cout<<start<<","<<end<<endl;
            // cout<<minstart<<","<<minend<<endl;
            // cout<<res<<endl;
            // cout<<"-----------"<<endl;
            if(isSame(tmp, smallset)){
                if(res>(end-start)){
                    minstart = start;
                    minend = end;
                    res = end-start;
                }
                start++;
                tmp.clear();
                tmp = unordered_set<int>(big.begin()+start,big.begin()+end+1);
            }else{
                end++;
                if(end<big.size())
                tmp.insert(big[end]);
            }
        }
        if(minstart==-1)return {};
        return {minstart,minend};
    }
    bool isSame(unordered_set<int>& tmp, unordered_set<int>& small){
        for(auto it = small.begin();it!=small.end();it++){
            if(tmp.count(*it)==0)return false;
        }
        return true;
    }
};


class Solution2 {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_set<int> smallset(small.begin(),small.end());
        if(big.size()<small.size())return {};
        unordered_map<int,int> tmp;
        for(int i=0;i<small.size();i++){
            tmp[big[i]]++;
        }
        int start = 0,end = small.size()-1;
        int res = big.size();
        int minstart=-1,minend=-1;
        while(start<big.size()&&end<big.size()&&start<=end){
            // cout<<start<<","<<end<<endl;
            // cout<<minstart<<","<<minend<<endl;
            // cout<<res<<endl;
            // cout<<"-----------"<<endl;
            if(isSame(tmp, smallset)){
                if(res>(end-start)){
                    minstart = start;
                    minend = end;
                    res = end-start;
                }
                
                tmp[big[start]]--;
                if(tmp[big[start]]<=0){
                    tmp.erase(big[start]);
                }
                start++;
                
            }else{
                end++;
                if(end<big.size())
                tmp[big[end]]++;
            }
        }
        if(minstart==-1)return {};
        return {minstart,minend};
    }
    bool isSame(unordered_map<int,int>& tmp, unordered_set<int>& small){
        for(auto it = small.begin();it!=small.end();it++){
            if(tmp.count(*it)==0)return false;
        }
        return true;
    }
};
int main(){
    Solution2 s = Solution2();
    vector<int> big = {7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7};
    vector<int> small = {1,5,9};
    vector<int> res = s.shortestSeq(big, small);
    print(res);
    return 0;
}
