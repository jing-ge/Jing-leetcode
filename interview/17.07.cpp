// 面试题 17.07. Baby Names LCCI
// Each year, the government releases a list of the 10000 most common baby names and their frequencies (the number of babies with that name). The only problem with this is that some names have multiple spellings. For example,"John" and ''Jon" are essentially the same name but would be listed separately in the list. Given two lists, one of names/frequencies and the other of pairs of equivalent names, write an algorithm to print a new list of the true frequency of each name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and Johnny are synonyms. (It is both transitive and symmetric.) In the final list, choose the name that are lexicographically smallest as the "real" name.

// Example:

// Input: names = ["John(15)","Jon(12)","Chris(13)","Kris(4)","Christopher(19)"], synonyms = ["(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"]
// Output: ["John(27)","Chris(36)"]
// Note:

// names.length <= 100000
// 通过次数4,903提交次数11,978

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        unordered_map<string,int>name2grpid;
        int grouppi=0;
        unordered_map<int,string>grpid2name;
        for(string &s:synonyms){
            int it = s.find(',');
            string name1 = s.substr(1,it-1),name2 = s.substr(it+1,s.size()-it-2);
            if(name2grpid.find(name1)==name2grpid.end()&&name2grpid.find(name2)==name2grpid.end()){
                name2grpid[name1] = grouppi;
                name2grpid[name2] = grouppi;
                grouppi++;
            }else if(name2grpid.find(name1)!=name2grpid.end()){
                int id = name2grpid[name1];
                name2grpid[name2] = id;
            }else{
                int id = name2grpid[name2];
                name2grpid[name1] = id;
            }
        }
        
        for(auto t:name2grpid){
            if(grpid2name.find(t.second)!=grpid2name.end()){
                if(t.first<grpid2name[t.second]){
                    grpid2name[t.second] = t.first;
                }
            }else{
                grpid2name[t.second] = t.first;
            }
        }
        vector<int> data(names.size()+1000,0);
        for(string &s:names){
            int it = s.find('(');
            string name = s.substr(0,it);
            int num = stoi(s.substr(it+1,s.size()-it-1));
            if(name2grpid.find(name)==name2grpid.end()){
                name2grpid[name] = grouppi;
                grpid2name[grouppi] = name;
                grouppi++;
            }
            data[name2grpid[name]]+=num;
        }
        vector<string>res;
        for(int i=0;i<grouppi;i++){
            if(data[i]>0){
                string tmp = grpid2name[i]+"("+to_string(data[i])+")";
                res.push_back(tmp);
            }
            
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    vector<string> names = {"Fcclu(70)","Ommjh(63)","Dnsay(60)","Qbmk(45)","Unsb(26)","Gauuk(75)","Wzyyim(34)","Bnea(55)","Kri(71)","Qnaakk(76)","Gnplfi(68)","Hfp(97)"};
    vector<string> synonyms = {"(Gnplfi,Qxabri)","(Uzgx,Siv)","(Bnea,Lucf)","(Qnaakk,Msyr)","(Grqrg,Gbclj)","(Uhsg,Qejo)","(Csh,Wpagta)","(Xjjol,Lucf)","(Qoi,Obcbxb)"};
    vector<string>res = s.trulyMostPopular(names,synonyms);
    for(string str:res){
        cout<<str<<endl;
    }
    return 0;
}
