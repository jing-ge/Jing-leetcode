// 860. Lemonade Change
// At a lemonade stand, each lemonade costs $5. 

// Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

// Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

// Note that you don't have any change in hand at first.

// Return true if and only if you can provide every customer with correct change.

//  

// Example 1:

// Input: [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.
// Example 2:

// Input: [5,5,10]
// Output: true
// Example 3:

// Input: [10,10]
// Output: false
// Example 4:

// Input: [5,5,10,10,20]
// Output: false
// Explanation: 
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can't give change of $15 back because we only have two $10 bills.
// Since not every customer received correct change, the answer is false.


#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& d){
    for(int i:d){
        cout<<i<<",";
    }
    cout<<endl;
}

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.size()<=0)return true;
        vector<int> cnt = {0,0,0};
        for(int &b:bills){
            if(b==5){
                cnt[2]++;
            }else if(b==10){
                if(cnt[2]>0){
                    cnt[2]--;
                    cnt[1]++;
                }else{
                    return false;
                }
            }else{
                if(cnt[1]>0&&cnt[2]>0){
                    cnt[0]++;
                    cnt[1]--;
                    cnt[2]--;
                }else if(cnt[2]>2){
                    cnt[2]-=3;
                }else{
                    return false;
                }
            }
            print(cnt);
        }
        return true;
    }
};

int main(){
    Solution s = Solution();
    vector<int> data = {5,5,5,5,20,20,5,5,20,5};
    bool res = s.lemonadeChange(data);
    cout<<res<<endl;
    return 0;
}