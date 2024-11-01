#include <bits/stdc++.h>
using namespace std;
map<string,vector<string>>mp;
void bfs(string s, string d,int a){
map<string,bool>vis;
vis[s]=true;
queue<string>q;
q.push(s);
map<string,int>lvl;
lvl[s]=0;

while(!q.empty()){
    string u=q.front();
    q.pop();
    for(int i=0;i<mp[u].size();i++){
        string child = mp[u][i];
        if(!vis[child]){
            q.push(child);
            vis[child] = true;
            lvl[child] = lvl[u]+1;
        }
        if(child==d) break;
    }
}
if(!lvl[d]) cout<<"NO SHIPMENT POSSIBLE\n";

else cout<<"$"<<(lvl[d]-lvl[s])*a<<endl;
}
int main(){ //freopen("383.txt","r",stdin);
cout<<"SHIPPING ROUTES OUTPUT\n";
int t;
cin>>t;
int tc=1;

while(t--){
        mp.clear();cout<<"\nDATA SET  "<<tc++<<endl<<endl;
    int n,e,cs; cin>>n>>e>>cs;
    while(n--){
        string s;   cin>>s; mp[s].push_back("");
    }
    while(e--){
        string a,b; cin>>a>>b; mp[a].push_back(b); mp[b].push_back(a);
    }

    while(cs--){
        int a; string b,c;
        cin>>a>>b>>c;   a*=100;
        bfs(b,c,a);
    }
}
cout<<"\nEND OF OUTPUT\n";


return 0;
}
