// 115. Distinct Subsequences
// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// It is guaranteed the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// Constraints:

// 0 <= s.length, t.length <= 1000
// s and t consist of English letters.
// 通过次数27,730提交次数54,071

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int res;
    int numDistinct(string s, string t) {
        // method 1 backtrack 
        res = 0;
        string tmp;
        backtrack(s,t,tmp,0);
        // method 2 dp
        // res = dp(s,t);
        return res;
    }
    void backtrack(string& s,string& t, string & tmp,int idx){
        if(tmp.size()==t.size()){
            if(tmp==t)res++;
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(tmp.size()>t.size())break;
            tmp.push_back(s[i]);
            backtrack(s,t,tmp,i+1);
            tmp.pop_back();
        }
    }
    int dp (string &s, string &t){
        int m = s.size(),n = t.size();
        if(m<n)return 0;
        vector<vector<long>> dp(m+1,vector<long>(n+1,0));
        for(int i=0;i<m+1;i++){
            dp[i][n]=1;
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        // for(int i=0;i<m+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         cout<<dp[i][j]<<",";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};

int main(){
    Solution sol;
    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo",t="rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    int res = sol.numDistinct(s,t);
    cout<<res<<endl;
    return 0;
}