// 1011. Capacity To Ship Packages Within D Days
// A conveyor belt has packages that must be shipped from one port to another within D days.

// The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

//  

// Example 1:

// Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
// Output: 15
// Explanation: 
// A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed. 
// Example 2:

// Input: weights = [3,2,2,4,1,4], D = 3
// Output: 6
// Explanation: 
// A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4
// Example 3:

// Input: weights = [1,2,3,1,1], D = 4
// Output: 3
// Explanation: 
// 1st day: 1
// 2nd day: 2
// 3rd day: 3
// 4th day: 1, 1
//  

// Constraints:

// 1 <= D <= weights.length <= 50000
// 1 <= weights[i] <= 500


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mymax(vector<int>&weights){
        int res = weights[0];
        for(int i:weights){
            res = res>i?res:i;
        }
        return res;
    }
    int mysum(vector<int>& weights){
        int res = 0;
        for(int& i:weights){
            res += i;
        }
        return res;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int left = mymax(weights);
        int right = mysum(weights)+1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(canFinish(weights,mid,D)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
    bool canFinish(vector<int>& weights,int mid,int D){
        int cnt = 0;
        int tmp = 0;
        int i = 0;
        while(i<weights.size()){
            tmp += weights[i];
            cout<<weights[i]<<endl;
            if(tmp>mid){
                tmp = 0;
                cnt++;
                cout<<"---------"<<cnt<<endl;
                continue;
            }
            i++;
        }
        if(tmp>0)cnt++;
        return cnt>D?false:true;
    }
};

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int D = 5;
    Solution s = Solution();
    int res = s.shipWithinDays(weights,D);
    cout<<res<<endl;
    // bool r = s.canFinish(weights,11,D);
    // cout<<r<<endl;
    return 0;
}