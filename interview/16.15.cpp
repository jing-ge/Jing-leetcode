// 面试题 16.15. Master Mind LCCI
// The Game of Master Mind is played as follows:

// The computer has four slots, and each slot will contain a ball that is red (R). yellow (Y). green (G) or blue (B). For example, the computer might have RGGB (Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).

// You, the user, are trying to guess the solution. You might, for example, guess YRGB.

// When you guess the correct color for the correct slot, you get a "hit:' If you guess a color that exists but is in the wrong slot, you get a "pseudo-hit:' Note that a slot that is a hit can never count as a pseudo-hit.

// For example, if the actual solution is RGBY and you guess GGRR, you have one hit and one pseudo-hit. Write a method that, given a guess and a solution, returns the number of hits and pseudo-hits.

// Given a sequence of colors solution, and a guess, write a method that return the number of hits and pseudo-hit answer, where answer[0] is the number of hits and answer[1] is the number of pseudo-hit.

// Example:

// Input:  solution="RGBY",guess="GGRR"
// Output:  [1,1]
// Explanation:  hit once, pseudo-hit once.
// Note:

// len(solution) = len(guess) = 4
// There are only "R","G","B","Y" in solution and guess.

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int n_right = 0,n_pseudo = 0;
        unordered_map<char,int> map = {{'R',0},{'Y',0},{'G',0},{'B',0}};
        for(int i = 0;i<solution.length();i++){
            if(solution[i]==guess[i]){
                n_right++;
            }else{
                if(map[solution[i]]++<0)n_pseudo++;
                if(map[guess[i]]-->0)n_pseudo++;
            }
        }
        return {n_right,n_pseudo};
    }
};

int main(){
    Solution s = Solution();
    vector<int>res = s.masterMind("RGRB","BBBY");
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}