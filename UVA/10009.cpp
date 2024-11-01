#include <bits/stdc++.h>
using namespace std;

map<string,vector<string>> graph;

void bfs(string s, string d){
    vector<char> v;
    map<string,string>par;
    map<string,bool>vis;
    par[s]="";
    vis[s]=true;
    queue<string>q;
    q.push(s);
    while(!q.empty()){
        string u = q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            string child=graph[u][i];
            if(!vis[child]){
            vis[child] = true;
            q.push(child);
            par[child] = u;
        }
        if(child==d)    break;
        }
    }
    string ss=d;
    while(1){

        if(ss=="") break;
        v.push_back(ss[0]);
        ss = par[ss];
    }
    for(int i=v.size()-1; i>=0;i--)
        cout<<v[i];
}
int main(){ //freopen("10009.txt","r",stdin);
int t;  cin>>t;
int c=0;
while(t--){
        graph.clear();
    int n,m;    cin>>n>>m;
    while(n--){
        string a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(c>0) cout<<endl;
    while(m--){
        string s,d; cin>>s>>d;
        bfs(s,d);
        cout<<endl;
    }
c++;
}
return 0;
}
