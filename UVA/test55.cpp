
#include <bits/stdc++.h>
using namespace std;

vector<string>v;

map<string,vector<string>> mp;
vector<bool>vis;
map<string,bool>visited;
map<string,int>lvl;
void func(string a){
    for(int i=0;i<v.size();i++){
        string tmp,cmp;
        tmp =v[i];
        cmp = a;
        int cnt=0;
     //   if(!vis[i]){
        for(int j=0;j<tmp.size();j++){
            if(tmp[j]!=cmp[j] && tmp.size()==cmp.size() ) cnt++;
            if(cnt>1) break;
       // }
    }
    if(cnt==1){
        mp[cmp].push_back(tmp);
    }
}
}

void bfs(string a,string b){
    for(auto it=visited.begin();it!=visited.end();++it)
        it->second=false;
lvl[a] = 0;
queue<string>q;
q.push(a);
visited[a]=true;
    while(!q.empty()){
        string u=q.front();
        q.pop();
        for(int i=0;i<mp[u].size();++i){
            string child =mp[u][i];
            if(!visited[child]){
                visited[child]=true;
                lvl[child]=lvl[u]+1;
                q.push(child);
            }
        }
        if(u==b) break;
    }

}
int main(){
//freopen("429.txt","r",stdin);
int t;
cin>>t;
while(t--){

    string ss,s;
    cin>>s;
    v.push_back(s);
    visited[s]= false;
    while(cin>>ss){
        if(ss=="*") break;
        v.push_back(ss);
      visited[ss]= false ;
}
//vis.assign(v.size(),false);
for(int i=0;i<v.size();i++){
    func(v[i]);
}
string f,l,line;
getline(cin,line);
while(getline(cin,line)){
    if(line=="")    break;
    int x=line.find(" ");
    f=line.substr(0,x);
    l=line.substr(x+1);
    bfs(f,l);
    cout<<f<<" "<<l<<" "<<lvl[l]<<endl;
}
if(t>0)cout<<endl;
v.clear();
mp.clear();
visited.clear();
lvl.clear();

}
return 0;
}
