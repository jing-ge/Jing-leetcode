#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int l = 0,r = words.size()-1;
        while (words[r]==""){r--;}
        while(words[l]=="")l++;
        while(l<=r){
            int mid = l+(r-l)/2;
            int i = 0;
            while(i<=(r-l)/2){
                if(words[mid+i]!=""){
                    mid = mid+i;
                    break;
                }
                if(words[mid-i]!=""){
                    mid = mid-i;
                    break;
                }
                i++;
            }
            if(words[mid]==s){
                return mid;
            }else if(words[mid]>s){
                r = mid-1;
            }else {
                l = mid +1;
            }
        }
        return -1;
    }
};

int main(){
    vector<string> words = {"at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""};
    string s = "ta";
    // cout<<(words[4]==s)<<endl;
    Solution sol = Solution();
    int res = sol.findString(words,s);
    cout<<res<<endl;
    return 0;
}