// 面试题 16.14. Best Line LCCI
// Given a two-dimensional graph with points on it, find a line which passes the most number of points.

// Assume all the points that passed by the line are stored in list S sorted by their number. You need to return {S{0}, S{1}}, that is , two points that have smallest number. If there are more than one line that passes the most number of points, choose the one that has the smallest S{0}. If there are more that one line that has the same S{0}, choose the one that has smallest S{1}.

// Example:

// Input:  {{0,0},{1,1},{1,0},{2,0}}
// Output:  {0,2}
// Explanation:  The numbers of points passed by the line are {0,2,3}.
// Note:

// 2 <= len(Points) <= 300
// len(Points{i}) = 2
// 通过次数2,041提交次数3,936


#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <string>

using namespace std;

void print(vector<int>&res){
    for(int &i:res){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        unordered_map<string,set<int>>map;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                string t = linek(points[i],points[j]);
                // cout<<t<<endl;
                map[t].insert(i);
                map[t].insert(j);
                // cout<<"-------------"<<endl;
            }
        }
        int t = 0;
        vector<int>res;
        for(auto item:map){
            if(item.second.size()>t){
                t = item.second.size();
                res = vector<int>(item.second.begin(),item.second.end());
            }
            if(item.second.size()==t){
                vector<int> temp(item.second.begin(),item.second.end());
                if(res[0]>temp[0])res =temp;
                if(res[0]==temp[0]&&res[1]>temp[1])res =temp;
            }
        }
        return {res[0],res[1]}; 
    }
    string linek(vector<int>&x,vector<int>&y){
        int A = y[1]-x[1];
        int B = x[0]-y[0];
        int C = (long)y[0]*x[1]-(long)x[0]*y[1];
        // cout<<A<<","<<B<<","<<C<<endl;
        int yue = divisor(divisor(abs(A),abs(B)),abs(C));
        A = A/yue;
        B = B/yue;
        C = C/yue;
        string res = to_string(A)+"," +to_string(B)+","+ to_string(C);
        return res;
    }
    //辗转相除法求最大公约数函数
    int divisor(int a, int b) {
        int temp;

        //比较两个数的大小，值大的数为a，值小的数为b
        if (a < b) {
            temp = a;
            a = b;
            b = temp;
        }

        //求余
        while (b != 0) {
            temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
};


int main(){
    Solution s = Solution();
    vector<vector<int>>points = {{-38935,27124},{-39837,19604},{-7086,42194},{-11571,-23257},{115,-23257},{20229,5976},{24653,-18488},{11017,21043},{-9353,16550},{-47076,15237}};
    vector<int> res = s.bestLine(points);
    print(res);
    return 0;
}