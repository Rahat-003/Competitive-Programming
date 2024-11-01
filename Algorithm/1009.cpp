#include <iostream>

#include <vector>
#include <memory.h>
using namespace std;

vector<vector<int> >graph(50005);
bool visited[50005];
bool visited1[50005];
int dfs(int s){
    int cnt=1;
visited[s]=true;
visited1[s]=true;
for(int i=0;i<graph[s].size();i++){
    int child=graph[s][i];
    if(!visited1[child])
        cnt+=dfs(child);
}
visited1[s]=false;
return cnt;

}

int main(){
int t;
cin>>t;
int k=0;
while(t--){
        for(int i=0;i<50005;i++)
            graph[i].clear();
        memset(visited,false,sizeof(visited));
        //memset(visited,false,sizeof(visited1));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);

    }
    int tempcnt,maxcnt,maxnode=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]) tempcnt+=dfs(i);
        if(tempcnt>maxcnt) maxcnt=tempcnt,maxnode=i;
    }
    cout<<"Case "<<++k<<": "<<maxnode<<endl;
}

return 0;
}
