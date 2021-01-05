// In a string s of lowercase letters, these letters form consecutive groups of the same character.

// For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

// A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

// A group is considered large if it has 3 or more characters.

// Return the intervals of every large group sorted in increasing order by start index.

//  

// Example 1:

// Input: s = "abbxxxxzzy"
// Output: [[3,6]]
// Explanation: "xxxx" is the only large group with start index 3 and end index 6.
// Example 2:

// Input: s = "abc"
// Output: []
// Explanation: We have groups "a", "b", and "c", none of which are large groups.
// Example 3:

// Input: s = "abcdddeeeeaabbbcd"
// Output: [[3,5],[6,9],[12,14]]
// Explanation: The large groups are "ddd", "eeee", and "bbb".
// Example 4:

// Input: s = "aba"
// Output: []
//  

// Constraints:

// 1 <= s.length <= 1000
// s contains lower-case English letters only

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/positions-of-large-groups
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<vector<int>>& res){
    for(auto& t:res){
        cout<<t[0]<<","<<t[1]<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        if(s.length()==0)return {{}};
        vector<vector<int>>res;
        int start = 0,end = 0;
        char t = s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==t){
                end = i;
            }
            else{
                if((end-start)>=2)
                res.push_back({start,end});                
                start = i;
                t = s[i];
            }
        }
        if((end-start)>=2)res.push_back({start,end}); 
        return res;
    }
};

int main(){
    Solution s = Solution();
    string str =  "abcdddeeeeaabbbcd";
    vector<vector<int>>res =  s.largeGroupPositions(str);
    print(res);
    return 0;
}