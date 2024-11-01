#include <bits/stdc++.h>
using namespace std;
map<string,vector<string> > mp;


void bfs(string s, string d){
    map<string,bool> vis;
    vis[s]=true;
map<string,string>par;
/*
for(auto it=mp.begin();it!=mp.end();it++)
    par[it->first]="";
*/
par[s]="";

queue<string> q;
q.push(s);
while(!q.empty()){
    string u=q.front();
    q.pop();
    for(auto it=mp[u].begin();it!=mp[u].end();++it){
        string child = *it;
    if(!vis[child]){
        vis[child]=true;
        q.push(child);
        par[child]=u;
    }
    if(u==d) break;
    }
}
vector<string>v;
int i=1;
if(!vis[d])
    cout<<"No route\n";
else{
        string ss=d;
    while(1){
        v.push_back(ss);
        ss=par[ss];
        if(ss=="") break;
    }

    for(i=v.size()-2;i>=0;i--)
     if(i!=-1)   cout<<par[v[i]]<<" "<<v[i]<<endl;
}
//if(i==-1) cout<<endl;
}


int main(){ //freopen("762.txt","r",stdin);
int t;int c=0;
while(cin>>t){

 mp.clear();
    while(t--){

        string a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
if(c>0) cout<<endl;
    string s,d;
    cin>>s>>d;
    bfs(s,d);

c++;
}

return 0;
}
