// 面试题 16.10. Living People LCCI
// Given a list of people with their birth and death years, implement a method to compute the year with the most number of people alive. You may assume that all people were born between 1900 and 2000 (inclusive). If a person was alive during any portion of that year, they should be included in that year's count. For example, Person (birth= 1908, death= 1909) is included in the counts for both 1908 and 1909.

// If there are more than one years that have the most number of people alive, return the smallest one.

// Example:

// Input: 
// birth = {1900, 1901, 1950}
// death = {1948, 1951, 2000}
// Output:  1901
// Note:

// 0 < birth.length == death.length <= 10000
// birth[i] <= death[i]
// 通过次数6,088提交次数8,875

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        unordered_map<int,int>map;
        for(int i=0;i<birth.size();i++){
            for(int j=birth[i];j<=death[i];j++){
                map[j]++;
            }
        }
        int maxnum = 0;
        int maxyear = 0;
        for(auto item:map){
            // cout<<item.first<<","<<item.second<<endl;
            if(maxnum<item.second){
                maxnum = item.second;
                maxyear = item.first;
            }
            if(maxnum==item.second&&maxyear>item.first){
                maxyear = item.first;
            }
        }
        return maxyear;
    }
};

int main(){
    vector<int> birth = {1900, 1901, 1950},death = {1948, 1951, 2000};
    Solution s =Solution();
    int res = s.maxAliveYear(birth,death);
    cout<<res<<endl;
    return 0;
}