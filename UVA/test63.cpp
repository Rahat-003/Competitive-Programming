
#include <bits/stdc++.h>
using namespace std;

int n;
map<int,vector<int>> graph;

void bfs(int s){
    map<int,bool>vis;
    map<int,int> df;

    vis[s]=true;

    queue<int> q;
    q.push(s);
    map<int,int>par;
    par[s]=-1;
    map<int,int> lvl;
    lvl[s]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
       // if(u==s) break;
       // cout<<u<<" ";
       // int cnt=0;
        for(int i=0;i<graph[u].size();++i){
            //int nchild=graph[u].size();
            int child = graph[u][i];

           // if(vis[child]) nchild--;
            if(!vis[child]){
                vis[child] = true;
                q.push(child);
                par[child] = u;
                lvl[child] = lvl[u] +1;

            }
        }
    }


    map<int,int> ll;
    vector<pair<int,int>>vv;
    int flag=-1;
    for(auto it=lvl.begin();it!=lvl.end();++it){
            int cnt=0;
     for(auto jt =lvl.begin();jt!=lvl.end();jt++){
        if(it->second==jt->second) {
                cnt++;
        }
     }
      ll[it->second] = cnt;
      if(cnt>flag){ flag=cnt;
        vv.clear();
        vv.push_back({flag, it->second});

      }
    }
    for(auto it=ll.begin();it!=ll.end();++it)
        cout<<it->first<<" "<<it->second<<endl;
 /*   for(auto it=lvl.begin();it!=lvl.end();++it)
        cout<<it->first<<" "<<it->second<<endl;

    if(!vv[0].second) cout<<0<<endl;
else cout<<vv[0].first<<" "<<vv[0].second<<endl;
*/
}


int main(){ freopen("924.txt","r",stdin);
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
  if(s!=-1)  bfs(s);
  s=-1;
}


return 0;
}
