// 1711. Count Good Meals
// A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.

// You can pick any two different foods to make a good meal.

// Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.

// Note that items with different indices are considered different even if they have the same deliciousness value.

 

// Example 1:

// Input: deliciousness = [1,3,5,7,9]
// Output: 4
// Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
// Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
// Example 2:

// Input: deliciousness = [1,1,1,3,3,3,7]
// Output: 15
// Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.
 

// Constraints:

// 1 <= deliciousness.length <= 105
// 0 <= deliciousness[i] <= 220
// 通过次数9,464提交次数30,727

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;
    int countPairs(vector<int>& deliciousness) {
        int max_val = max_vec(deliciousness);
        int sum_max = max_val*2;
        int res = 0;
        unordered_map<int,int> mp;
        for(int &i:deliciousness){
            for(int sum = 1;sum<=sum_max;sum <<=1){
                int cnt = mp.count(sum-i)?mp[sum-i]:0;
                res = (res+cnt)%MOD;
            }
            mp[i]++;
        }
        return res;
    }
    int max_vec(vector<int> &nums){
        int res = nums[0];
        for(int &i:nums){
            res = max(res,i);
        }
        return res;
    }
};

int main(){
    vector<int> deliciousness = {1,3,5,7,9};
    Solution s;
    int res = s.countPairs(deliciousness);
    cout<<res<<endl;
    return 0;
}
