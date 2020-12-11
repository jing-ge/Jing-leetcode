// 875. Koko Eating Bananas
// Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.

// Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.

// Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

// Return the minimum integer K such that she can eat all the bananas within H hours.

//  

// Example 1:

// Input: piles = [3,6,7,11], H = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], H = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], H = 6
// Output: 23


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mymax(vector<int> piles){
        int res = 0;
        for(int i:piles){
            if(res<i)
                res = i;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int max = mymax(piles);
        for(int i=1;i<max;i++){
            if(canFinish(piles,i,H)){
                return i;
            }
        }
        return max;
    }
    int minEatingSpeed2(vector<int>& piles, int H) {
        int left = 0;
        int right = mymax(piles) + 1;
        while (left<right)
        {
            int mid = left + (right-left)/2;
            if(canFinish(piles,mid,H)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
    bool canFinish(vector<int>& piles,int speed, int H){
        bool res = true;
        int ans = 0;
        for(int i:piles){
            ans+= i/speed+((i%speed>0)?1:0);
            if(ans>H)return false;
        }
        return true;
    }
};

int main(){
    Solution s = Solution();
    vector<int> piles = {30,11,23,4,20};
    int H = 6;
    int res = s.minEatingSpeed(piles,H);
    cout<<res<<endl;
    return 0;
}