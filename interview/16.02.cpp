// 面试题 16.02. Words Frequency LCCI
// Design a method to find the frequency of occurrences of any given word in a book. What if we were running this algorithm multiple times?

// You should implement following methods:

// WordsFrequency(book) constructor, parameter is a array of strings, representing the book.
// get(word) get the frequency of word in the book. 
// Example:

// WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
// wordsFrequency.get("you"); //returns 0，"you" is not in the book
// wordsFrequency.get("have"); //returns 2，"have" occurs twice in the book
// wordsFrequency.get("an"); //returns 1
// wordsFrequency.get("apple"); //returns 1
// wordsFrequency.get("pen"); //returns 1
// Note:

// There are only lowercase letters in book[i].
// 1 <= book.length <= 100000
// 1 <= book[i].length <= 10
// get function will not be called more than 100000 times.
// 通过次数8,239提交次数10,882

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class WordsFrequency {
public:
    unordered_map<string,int> map;
    WordsFrequency(vector<string>& book) {
        for(string &s:book){
            map[s]++;
        }
    }
    
    int get(string word) {
        return map[word];
    }
};

int main(){
    vector<string>data = {"i", "have", "an", "apple", "he", "have", "a", "pen"};
    WordsFrequency wordsFrequency = WordsFrequency(data);
    wordsFrequency.get("you"); //返回0，"you"没有出现过
    wordsFrequency.get("have"); //返回2，"have"出现2次
    wordsFrequency.get("an"); //返回1
    wordsFrequency.get("apple"); //返回1
    wordsFrequency.get("pen"); //返回1
    return 0;
}