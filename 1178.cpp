// 1178. Number of Valid Words for Each Puzzle
// With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
// word contains the first letter of puzzle.
// For each letter in word, that letter is in puzzle.
// For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).
// Return an array answer, where answer[i] is the number of words in the given word list words that are valid with respect to the puzzle puzzles[i].
 

// Example :

// Input: 
// words = ["aaaa","asas","able","ability","actt","actor","access"], 
// puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
// Output: [1,1,3,2,4,0]
// Explanation:
// 1 valid word for "aboveyz" : "aaaa" 
// 1 valid word for "abrodyz" : "aaaa"
// 3 valid words for "abslute" : "aaaa", "asas", "able"
// 2 valid words for "absoryz" : "aaaa", "asas"
// 4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
// There're no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
 

// Constraints:

// 1 <= words.length <= 10^5
// 4 <= words[i].length <= 50
// 1 <= puzzles.length <= 10^4
// puzzles[i].length == 7
// words[i][j], puzzles[i][j] are English lowercase letters.
// Each puzzles[i] doesn't contain repeated characters.
// 通过次数4,495提交次数11,856

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //超时
    vector<int> findNumOfValidWords1(vector<string>& words, vector<string>& puzzles) {
        vector<unordered_set<char>> setpuzz;
        for(string &s: puzzles)setpuzz.push_back(unordered_set<char>(s.begin(),s.end()));
        vector<int> res;
        for(int i=0;i<puzzles.size();i++){
            int t = 0;
            for(string &ss: words){
                if(ss.find(puzzles[i][0])==ss.npos)continue;
                bool flag = true;
                for(char &c:ss){
                    if(setpuzz[i].count(c)==0)flag = false;
                }
                if(flag)t++;
            }
            res.push_back(t);
        }
        return res;
    }
     vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles){
         unordered_map<int,int> frequency;

         for(string & word:words){
             int mask = 0;
             for(char ch :word){
                 mask |= (1<<(ch-'a'));
             }
             if(__builtin_popcount(mask)<=7){
                 frequency[mask]++;
             }
         }
         vector<int> res;
         for(string &puzzle:puzzles){
             int total = 0;
             int mask = 0;
             for(int i=1;i<7;i++){
                 mask |= (1<<(puzzle[i]-'a'));
             }
             int subset = mask;
             do
             {
                 int s = subset | (1<<(puzzle[0]  - 'a'));
                 if(frequency.count(s))total += frequency[s];
                 subset = (subset - 1) & mask;
             } while (subset!=mask);
             res.push_back(total);
         }
         return res;
     }
};

int main(){
    Solution s;
    vector<string> words = {"aaaa","asas","able","ability","actt","actor","access"},puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    vector<int> res = s.findNumOfValidWords(words,puzzles);
    for(auto i:res)cout<<i<<",";
    cout<<endl;
    return 0;
}