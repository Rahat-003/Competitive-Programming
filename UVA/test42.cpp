#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
int n;
bool check(){

int s=0;
vector <bool> clr(n,false);
queue<int>q;
q.push(s);
clr[s]=true;
while(!q.empty()){

    int u=q.front();
    q.pop();
    for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
        if(!clr[v]){
            clr[v]=!clr[u];
            q.push(v);
        }
        else if(clr[v]==clr[u])
                return false;
    }
}
return true;
}

int main(){

cin>>n;
graph.assign(n+1,vector<int>());
int e;
cin>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}

cout<<check()<<endl;
return 0;
}
