// 剑指 Offer 11. 旋转数组的最小数字
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

// 示例 1：

// 输入：[3,4,5,1,2]
// 输出：1
// 示例 2：

// 输入：[2,2,2,0,1]
// 输出：0
// 注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

// 通过次数216,963提交次数439,671

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minArray_(vector<int>& numbers) {
        if(numbers.size()==1)return numbers[0];
        for(int i=1;i<numbers.size();i++){
            if(numbers[i]<numbers[i-1])return numbers[i];
        }
        return numbers[0];
    }
    int minArray(vector<int> &numbers) {
        int l = 0,r = numbers.size()-1;
        while (l<r)
        {
            int mid = l+(r-l)/2;
            if(numbers[mid]<numbers[r]){
                r = mid;
            }else if(numbers[mid]>numbers[r]){
                l = mid+1;
            }else{
                r--;
            }
        }
        return numbers[l];
    }
};

int main(){
    vector<int> numbers = {3,4,5,1,2};
    Solution s;
    int res = s.minArray(numbers);
    cout<<res<<endl;
    return 0;
}