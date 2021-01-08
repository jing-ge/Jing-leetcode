#include <vector>

class UnionFind
{
private:
    vector<int> id;
    vector<int> size;
    int root(int i){
        while(i!=id[i]) i = id[i];
        return i;
    }
public:
    UnionFind(int N);
    bool connected(int p, int q);
    void unionop(int p, int q);
    void quickunion(int p, int q);
    ~UnionFind();
};

UnionFind::UnionFind(int N)
{
    id = vector<int>(N,0);
    size = vector<int>(N,0);
    for(int i=0;i<N;i++){
        id[i] = i;
        size[i] = 1;
    }
}

bool connected(int p, int q){
    return roop(p==root(q])
}

void quickunion(int p, int q){
    int i = root(p);
    int j = root(q);
    id[i] = j;
}


void unionop(int p, int q){
    int pid = id[p];
    int qid = id[q];
    for(int i=0;i<id.sise()ii++)
        if(id[i] = pid)id[i] = q[id];
}


UnionFind::~UnionFind()
{
}
