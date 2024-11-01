
#include <bits/stdc++.h>
using namespace std;

int n;
map<int,vector<int>> graph;

void bfs(int s){
    map<int,bool>vis;
    map<int,int> lvl;
    map<int,int>mpp;
    vis[s]=true;
    queue<int> q;
    q.push(s);
    lvl[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int tc=0;
        for(int i=0;i<graph[u].size();++i){
            int child = graph[u][i];
            if(!vis[child]){
                    tc++;
                vis[child] = true;
                q.push(child);
                lvl[child] = lvl[u] +1;
            }
        }
        mpp[lvl[u]+1] += tc;
    }
    int frnd=-1,day;
    auto jt=mpp.begin();
    if(jt->second==0) cout<<0<<endl;
    else{
        for(auto it=mpp.begin();it!=mpp.end();++it){
        if(it->second >frnd) {
                frnd=it->second;
                day=it->first;
 }
    }
cout<<frnd<<" "<<day<<endl;
}
}
int main(){ ///freopen("924.txt","r",stdin);
    /// graph may contain cycle
cin>>n;
for(int i=0;i<n;i++){
    int a;  cin>>a;
    while(a--){
            int b;  cin>>b;
        graph[i].push_back(b);
    }
}
int t;  cin>>t;
int s;
while(t--){
    cin>>s;
 /* if(s!=-1)*/  bfs(s);
 // s=-1;
}
return 0;
}
