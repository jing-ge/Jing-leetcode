#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& data){
    for(auto&t:data){
        for(int i:t){
            cout<<i<<",";
        }
        cout<<endl;
    }
}

int finalres = -1;

int dfs(int i,int j, int t, vector<vector<int>>& matrix){
    int m = matrix.size(),n = matrix[0].size();
    if(i==m-1&&j==n-1)finalres = t;
    if(i==m&&j==n){
        return t;
    }
    // cout<<i<<","<<j<<","<<t<<endl;
    if(i>=m||j>=n||matrix[i][j]-t<0)return -1;
    int a,b;
    if(i<m)
    a = dfs(i+1,j,t+1,matrix);
    if(j<n)
    b = dfs(i,j+1,t+1,matrix);
    if(a==-1&&b==-1)return -1;
    if(a==-1)return b;
    if(b==-1)return a;
    return a>b?b:a;
}

int getRes(vector<vector<int>>& matrix){
    dfs(0,0,0,matrix);
    return finalres;
}

int main(){
    
    // vector<vector<int>> matrix = {{2,3,2},{5,1,1},{4,5,5}};

    // vector<vector<int>> matrix  = {{3,5,4,2,3},{4,5,3,4,3},{4,3,5,3,2},{2,5,3,3,5},{5,3,4,4,3}};
    vector<vector<int>> matrix;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            tmp.push_back(t);
        }
        matrix.push_back(tmp);
    }
    // print(matrix);
    cout<<getRes(matrix)<<endl;
    return 0;
}

/*
3 3
2 3 2
5 1 1
4 5 5
*/