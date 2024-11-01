#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>>mp;
void edge(int a,int b){
mp[a].push_back(b);
mp[b].push_back(a);
}
void bfs(int s,int d){
    queue<int>q;
    map<int,int>lvl;
    map<int,bool>vis;
    map<int,int>str;
    lvl[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int u;

        u=q.front();
        q.pop();
        for(auto it=mp[u].begin();it!=mp[u].end();++it){
          if(vis[*it]==false){
            vis[*it]=true;
            q.push(*it);
            lvl[*it]=lvl[u]+1;
            str[*it]=u;
          }
        }
    }

        cout<<d<<" "<<lvl[d]<<endl;

}

int main(){
int e;
cin>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    edge(a,b);
}
int s,d;
cin>>s>>d;
bfs(s,d);
}
