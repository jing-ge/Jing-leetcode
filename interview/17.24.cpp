// 面试题 17.24. Max Submatrix LCCI
// Given an NxN matrix of positive and negative integers, write code to find the submatrix with the largest possible sum.

// Return an array [r1, c1, r2, c2], where r1, c1 are the row number and the column number of the submatrix's upper left corner respectively, and r2, c2 are the row number of and the column number of lower right corner. If there are more than one answers, return any one of them.

// Note: This problem is slightly different from the original one in the book.

// Example:

// Input:
// [
//    [-1,0],
//    [0,-1]
// ]
// Output: [0,1,0,1]
// Note:

// 1 <= matrix.length, matrix[0].length <= 200

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> & nums){
    for(int i:nums)cout<<i<<",";
    cout<<endl;
}


class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        vector<int> res = {0,0,0,0};
        int t = matrix[0][0];
        int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int> dp(m,0);
            for(int j=i;j<n;j++){
                add(dp,matrix[j]);
                vector<int>tmp = maxSubArray(dp);
                print(dp);
                cout<<tmp[0]<<","<<tmp[1]<<","<<tmp[2]<<endl;
                if(tmp[2]>t){
                    res[0] = i;
                    res[1] = tmp[0];
                    res[2] = j;
                    res[3] = tmp[1];
                    t = tmp[2];
                }
            }
        }
        cout<<t<<endl;
        return res;
    }
    void add(vector<int>& a,vector<int>& b){
        for(int i=0;i<a.size();i++){
            a[i]+=b[i];
        }
    }
    vector<int> maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int t = nums[0];
        int start = 0,end = 0;
        int begin = 0;
        for(int i=1;i<nums.size();i++){
            if(t<0)begin = i;
            t = max(t+nums[i],nums[i]);
            
            if(res<t){
                start = begin;
                end = i;
            }
            res = max(res,t);
            
        }
        return {start,end,res};
    }
};

int main(){
    vector<vector<int>> matrix = {{-5208, 1041, -93779, -64152, 17850, 29055, -63731, -23568, 41170, 58457, -39616, 55683, -51662, -75015, 21726}, {4535, -72412, 86878, -60825, 67088, 48794, -23471, -22403, 58200, -31153, -94668, -27274, -11003, 33894, -66125}, {-9538, -33861, 54822, 42636, 48430, -56030, -33348, -30617, 5219, 56501, -95879, -73537, -18157, -72815, -40977}, {15602, 40115, -32475, 99011, 47251, 84035, 83793, -74389, -99042, 65460, 11671, -95294, 68311, 47893, 71866}, {69607, 57288, 55022, 36610, -75113, 31344, 34319, -13381, -74800, -71904, -15625, -5398, -29689, -68805, -41994}, {-32276, 95017, -96452, -47311, 13238, 46324, 95358, 13247, -30930, 5815, -36748, -25712, -83982, 29391, -73922}, {-29140, -70403, -3168, 12219, -4473, -10013, -85502, 87222, -44858, 66506, -99821, -16992, -80758, 59210, 87145}, {-9557, 67725, -27359, -28647, 46781, -67948, -28154, -3498, 91489, -3887, -96422, 6568, 42380, 73264, -55406}, {40555, 70153, -51490, -14237, 9684, -54000, -8443, -32063, -96157, -70083, -7050, 56221, 93013, -1157, -45593}, {-28686, -54296, 628, 11189, 18227, -64455, -10528, -69244, 94796, -39806, 69194, 45024, -14417, -51291, 6387}, {-28485, 36898, 97259, -83875, 83650, -36715, 80692, -55055, 40025, -69379, -1548, -13045, 23318, 79349, -42774}, {82645, 17721, 84052, -35036, -751, 90269, -77187, 51972, -90217, -5956, -34552, 95560, 40436, 51650, 72778}, {-970, 77788, 10423, -1406, -90844, 6732, -60197, 59393, -82111, 33737, -4731, -52679, -12011, 69741, -91931}};
    Solution s = Solution();
    vector<int> nums = {9,-8,1,3,-2};
    // vector<int> res = s.maxSubArray(nums);
    // cout<<res[0]<<","<<res[1]<<","<<res[2]<<endl;
    vector<int> res = s.getMaxMatrix(matrix);
    cout<<res[0]<<","<<res[1]<<","<<res[2]<<","<<res[3]<<endl;
    return 0;
}