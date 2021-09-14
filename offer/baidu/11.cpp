#include<iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 5e5+100;
typedef long long LL;
struct Task{
    int E,W;
};

Task task[maxn];

bool cmp(Task a,Task b){
    return a.E<b.E;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&task[i].E,&task[i].W);
    }
    priority_queue<int,vector<int>,greater<int>> que;
    sort(task,task+n,cmp);
    for(int i=0;i<n;i++){
        if(task[i].E>que.size()*10){
            que.push(task[i].W);
        }
        else{
            que.push(task[i].W);
            que.pop();
        }
    }
    LL ans = 0;
    while (que.size())
    {
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
    return 0;
}