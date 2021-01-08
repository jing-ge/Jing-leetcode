// 面试题 17.14. Smallest K LCCI
// Design an algorithm to find the smallest K numbers in an array.

// Example:

// Input:  arr = [1,3,5,7,2,4,6,8], k = 4
// Output:  [1,2,3,4]
// Note:

// 0 <= len(arr) <= 100000
// 0 <= k <= min(100000, len(arr))

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
vector<int>res;
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k==0||arr.size()==0)return {};
        
        int l = 0,r = arr.size()-1;
        while (true){
            int idx =qs(arr,l,r);
            if(idx==k){
                return vector<int>(res.begin(),res.begin()+k);
            }else if(idx>k){
                r = idx-1;
            }else{
                l = idx+1;
            }
        }
    }
    int qs(vector<int>&arr,int i,int j){
        int t = arr[i],pviot = i;
        int l = i+1,r = j;
        while(l<r){
            while(l<=j&&arr[l]<t)l++;
            while(r>=i&&arr[r]>t)r--;
            swap(arr[l],arr[r]);
            l++;r--;
        }
        swap(arr[i],arr[r]);
        return r;
    }
};

int main(){
    vector<int>arr = {1,3,5,7,2,4,6,8};
    int k = 4;
    Solution s= Solution();
    vector<int>res = s.smallestK(arr,k);
    for(int i:res)cout<<i<<",";
    cout<<endl;
    return 0;
}