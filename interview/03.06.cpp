// 面试题 03.06. Animal Shelter LCCI
// An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. People must adopt either the"oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linked list data structure.

// enqueue method has a animal parameter, animal[0] represents the number of the animal, animal[1] represents the type of the animal, 0 for cat and 1 for dog.

// dequeue* method returns [animal number, animal type], if there's no animal that can be adopted, return [-1, -1].

// Example1:

//  Input: 
// ["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
// [[], [[0, 0]], [[1, 0]], [], [], []]
//  Output: 
// [null,null,null,[0,0],[-1,-1],[1,0]]
// Example2:

//  Input: 
// ["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
// [[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
//  Output: 
// [null,null,null,null,[2,1],[0,0],[1,0]]

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class AnimalShelf {
public:
    queue<vector<int>> cat;
    queue<vector<int>> dog;
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if(animal[1]==0){
            cat.push(animal);
        }else{
            dog.push(animal);
        }
    }
    
    vector<int> dequeueAny() {
        if(cat.empty()&&dog.empty()){
            return {-1,-1};
        }else if(!cat.empty()&&dog.empty()){
            vector<int>res = cat.front();
            cat.pop();
            return res;
        }else if(cat.empty()&&!dog.empty()){
            vector<int>res = dog.front();
            dog.pop();
            return res;
        }else{
            vector<int> tcat = cat.front();
            vector<int> tdog = dog.front();
            if(tcat[0]<tdog[0]){
                cat.pop();
                return tcat;
            }else{
                dog.pop();
                return tdog;
            }
        }
    }
    
    vector<int> dequeueDog() {
        if(dog.empty())return {-1,-1};
        vector<int>res = dog.front();
        dog.pop();
        return res;
    }
    
    vector<int> dequeueCat() {
        if(cat.empty())return {-1,-1};
        vector<int>res = cat.front();
        cat.pop();
        return res;
    }
};


int main(){
    AnimalShelf* obj = new AnimalShelf();
    obj->enqueue({0,0});
    obj->enqueue({1,0});
    obj->enqueue({2,1});
    vector<int> param_3 = obj->dequeueDog();
    vector<int> param_4 = obj->dequeueCat();
    vector<int> param_2 = obj->dequeueAny();
    return 0;
}