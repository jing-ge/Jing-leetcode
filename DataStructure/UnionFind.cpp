#include <vector>


class UnionFind{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    UnionFind(int _n){
        n = _n;
        for(int i=-0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int root(int i){
        while(parent[i]!=i){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    bool merge(int i, int j){
        i = root(i);
        j = root(j);
        if(i==j)return false;
        if(size[i]<size[j]){
            parent[i] = j;
            size[j]+=size[i];
        }else{
            parent[j] = i;
            size[i] += size[j];
        }
        n--;
        return true;
    }
};
