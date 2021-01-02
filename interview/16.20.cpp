// 面试题 16.20. T9 LCCI
// On old cell phones, users typed on a numeric keypad and the phone would provide a list of words that matched these numbers. Each digit mapped to a set of 0 - 4 letters. Implement an algo­rithm to return a list of matching words, given a sequence of digits. You are provided a list of valid words. The mapping is shown in the diagram below:



// Example 1:

// Input: num = "8733", words = ["tree", "used"]
// Output: ["tree", "used"]
// Example 2:

// Input: num = '2', words = ["a", "b", "c", "d"]
// Output: ["a", "b", "c"]
// Note:

// num.length <= 1000
// words.length <= 500
// words[i].length == num.length
// There are no number 0 and 1 in num.

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string>res;
    vector<string> getValidT9Words(string num, vector<string>& words) {
        unordered_map<char,string> map = {{'0',""},{'1',""},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string>temp;
        for(char c:num){
            temp.push_back(map[c]);
        }
        string s;
        bfs(temp,0,s);
        vector<string>r;
        for(string t:res){
            if(find(words.begin(),words.end(),t)!=words.end())r.push_back(t);
        }
        return r;
    }
    void bfs(vector<string>& temp,int i,string &t){
        if(i==temp.size()){
            res.push_back(t);
            return;
        }else{
            for(char c:temp[i]){
                string b(1,c);
                string tt = t+b;
                bfs(temp,i+1,tt);
            }
        }
    }
    bool myfind(string &t,vector<string>& words){
        for(string&i:words){
            if(t==i)return true;
        }
        return false;
    }
    vector<string> getValidT9Words2(string num, vector<string>& words){
        unordered_map<char,char> map ={{'a','2'},{'b','2'},{'c','2'},{'d','3'},{'e','3'},{'f','3'},{'g','4'},{'h','4'},{'i','4'},{'j','5'},{'k','5'},{'l','5'},{'m','6'},{'n','6'},{'o','6'},{'p','7'},{'q','7'},{'r','7'},{'s','7'},{'t','8'},{'u','8'},{'v','8'},{'w','9'},{'x','9'},{'y','9'},{'z','9'}};
        vector<string>res;
        for(string s:words){
            if(s.length()!=num.length()){
                continue;
            }else{
                bool flag = true;
                for(int i=0;i<s.length();i++){
                    if(map[s[i]]!=num[i]){
                        flag =false;
                        break;
                    }
                }
                if(flag)
                res.push_back(s);
            }
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    string num = "2";
    vector<string> words = {"a","b","c","d"};
    vector<string>res = s.getValidT9Words2(num,words);
    for(auto t:res){
        cout<<t<<endl;
    }
    return 0;
}