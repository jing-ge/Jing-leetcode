// 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
// 示例 1:
// 输入: [10,1,2]
// 输出: 2110
// 示例 2:
// 输入: [3,30,34,5,9]
// 输出: 9534330

// 作者：字节校园
// 链接：https://leetcode-cn.com/leetbook/read/bytedance-c01/eus0ut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string maxNUmbert(vector<int> nums){
        vector<string> temp;
        for(int i:nums){
            temp.push_back(to_string(i));
        }
        sort(temp.begin(),temp.end(),[](string &a, string &b)->bool{
            return a+b>b+a;
        });
        string res;
        for(auto &t:temp){
            res+=t;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    string input;
    cin>>input;
    int start = 0;
    for(int i=0;i<input.size();i++){
        if(input[i]=='['){
            start = i+1;
        }else if(input[i]==','||input[i]==']'){
            nums.push_back(stoi(input.substr(start,i-start)));
            start = i+1;
        }
    }
    // for(int i:nums){
    //     cout<<i<<',';
    // }
    // cout<<endl;
    string res = s.maxNUmbert(nums);
    cout<<res<<endl;
    return 0;
}