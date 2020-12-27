// 面试题 16.09. Operations LCCI
// rite methods to implement the multiply, subtract, and divide operations for integers. The results of all of these are integers. Use only the add operator.

// You should implement following methods:

// Operations()  constructor
// minus(a, b)  Subtraction, returns a - b
// multiply(a, b)  Multiplication, returns a * b
// divide(a, b)  Division, returns a / b
// Example:

// Operations operations = new Operations();
// operations.minus(1, 2); //returns -1
// operations.multiply(3, 4); //returns 12
// operations.divide(5, -2); //returns -2
// Note:

// You can assume inputs are always valid, that is, e.g., denominator will not be 0 in division.
// The number of calls will not exceed 1000.
// 通过次数1,244提交次数2,426

#include <iostream>
#include <vector>

using namespace std;

class Operations {
public:
    vector<int> negs,poss;
    Operations() {
        int p=1,n=-1;
        poss.push_back(p);
        negs.push_back(n);
        for(int i=0;i<30;i++){
            p+=p;
            n+=n;
            poss.push_back(p);
            negs.push_back(n);
        }
    }
    
    int neg(int a){
        if(!a)return 0;
        int result = 0;
        if(a>0){
            for(auto p = negs.rbegin();p!=negs.rend();p++){
                if(*p+a<0)continue;
                a+=*p;
                result += *p;
            }
        }else{
            for(auto p = poss.rbegin();p!=poss.rend();p++){
                if(*p+a>0)continue;
                a+=*p;
                result += *p;
            }
        }
        return result;
    }

    int minus(int a, int b) {
        return a+neg(b);
    }
    
    int multiply(int a, int b) {
        if(a==0||b==0)return 0;
        if(a==1)return b;
        if(b==1)return a;
        if(b<0)return neg(multiply(a,neg(b)));

        int result = a;
        int times = 1;
        while(times<poss[30]&&times+times<=b){
            result+=result;
            times+=times;
        }
        result += multiply(a,minus(b,times));
        return result;
    }
    
    int divide(int a, int b) {
        if(!a)return 0;
        int result = 1;
        if(a>0){
            if(b==INT64_MIN) return 0;
            if(b<0)return neg(divide(a,neg(b)));
            if(a<b)return 0;
            int acc = b;
            while(acc<poss[30]&&a>=acc+acc){
                result += result;
                acc += acc;
            }
            result += divide(minus(a,acc),b);
        }else{
            if(b==1)return a;
            if(b>0)return neg(divide(a,neg(b)));
            if(a>b) return 0;
            int acc = b;
            while(acc>=negs[30]&&a<=acc+acc){
                result += result;
                acc+=acc;
            }
            result += divide(minus(a,acc),b);
        }
        return result;
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */

int main(){
    Operations operations = Operations();
    cout<<1<<endl;
    operations.minus(1, 2); //returns -1
    cout<<1<<endl;
    operations.multiply(3, 4); //returns 12
    cout<<1<<endl;
    operations.divide(5, -2); //returns -2
    cout<<1<<endl;
    return 0;
}