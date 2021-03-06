// 726. Number of Atoms
// Given a chemical formula (given as a string), return the count of each atom.

// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

// Two formulas concatenated together to produce another formula. For example, H2O2He3Mg4 is also a formula.

// A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

// Given a formula, return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

 

 

// Example 1:

// Input: formula = "H2O"
// Output: "H2O"
// Explanation: The count of elements are {'H': 2, 'O': 1}.
// Example 2:

// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
// Example 3:

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
// Example 4:

// Input: formula = "Be32"
// Output: "Be32"
 

// Constraints:

// 1 <= formula.length <= 1000
// formula consists of English letters, digits, '(', and ')'.
// formula is always valid.
// 通过次数5,129提交次数11,263

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int i;
    string str;
    string countOfAtoms(string formula) {
        i = 0;
        str = formula;
        map<string,int> mymap = parse();
        string res;
        for(auto t:mymap){
            res+=t.first;
            if(t.second>1){
                res+=to_string(t.second);
            }
        }
        return res;
    }
    map<string,int> parse(){
        map<string,int> mymap;
        int N = str.size();
        while(i<N && str[i]!=')'){
            if(str[i]=='('){
                i++;
                for(auto &t:parse()){
                    mymap[t.first]+=t.second;
                }
            }else{
                int start = i;
                i++;
                while(i<N&&str[i]>='a'&&str[i]<='z')i++;
                string name = str.substr(start,i-start);
                start = i;
                while(i<N&&str[i]>='0'&&str[i]<='9')i++;
                if(start==i){
                    mymap[name]++;
                }else{
                    mymap[name]+=stoi(str.substr(start,i-start));
                }
            }
        }
        i++;
        int start = i;
        while(i<N&&str[i]>='0'&&str[i]<='9')i++;
        if(start<i){
            int mulp = stoi(str.substr(start,i-start)); // 这句一定要写在if里面，在外面可能会导致取不到数字
            for(auto &t:mymap){
                mymap[t.first]*=mulp;
            }
        }
        return  mymap;
    }
};

int main(){
    string formula =  "Mg(OH)2";
    Solution s;
    string res = s.countOfAtoms(formula);
    cout<<res<<endl;
    return 0;
}