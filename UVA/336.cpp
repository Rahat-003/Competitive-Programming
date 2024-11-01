#include <bits/stdc++.h>
using namespace std;
queue<int>q;
map<int,bool>vis;
map<int,int>lvl;
map <int,vector<int> > mp;

void ch(int a){
    q.push(a);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i =0; i<mp[u].size();++i){
            int child = mp[u][i];
            if(!vis[child]){
                vis[child]=true;
                q.push(child);

                if(!lvl[u]){
                        lvl[u]=1e5;
                lvl[child]=lvl[u]+1;
                }
                else lvl[child] = lvl[u]+1;
            }
        }
    }
}
void check(int c,int d,int cnt){
  lvl[c]=01;
  vis[c]=true;
    ch(c);
    for(auto it=mp.begin();it!=mp.end();++it){
        if(!vis[it->first])
            ch(it->first);
    }
}
int main(){
 // freopen("336.txt","r",stdin);
int n;
int tc=1;
while(cin>>n){
    if(n==0)    break;
mp.clear();
    while(n--){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    int c,d;
    while(cin>>c>>d){
            int cnt=0;
        if(c==0 && d==0) break;
        vis.clear();
        lvl.clear();
     check(c,d,0);
        for(auto it=lvl.begin();it!=lvl.end();it++)
     if(it->second > d+1) cnt++;
     printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc++,cnt,c,d);
    }
mp.clear();
}
return 0;
}
