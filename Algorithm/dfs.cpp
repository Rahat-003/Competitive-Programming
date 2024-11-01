#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > graph(1001);
int n;
bool visited[1001];

void dfs(int s){

visited[s]=true;
cout<<s<<" ";
for(int i=0;i<graph[s].size();i++){
    int child=graph[s][i];
    if(!visited[child])
        dfs(child);
}
}
int main(){
cin>>n;
int e;
cin>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}
memset(visited,false,sizeof(visited));
dfs(1);/*
for(int i=2;i<=n;i++)
    if(!visited[i])
        dfs(i);*/
return 0;
}
