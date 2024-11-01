#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

vector<vector<pp>> v;
#define inf 2e9

int n,e;

void dj(int s,int d){
  vector<int> dis(n,inf);
  dis[s] = 0;
  priority_queue<pp,vector<pp>,greater<pp>> pq;
  pq.push(pp(0,s));

  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    for(int i = 0;i<v[u].size(); i++){
      int child  = v[u][i].first;
      int w = v[u][i].second;
      if(dis[u]+w<dis[child]){
        dis[child] = dis[u]+w;
        pq.push(pp(dis[child],child));
      }
    }
  }

  for(int i = 0;i<dis.size(); i++)
    cout<<i<<" "<<dis[i]<<endl;

  /**
  vector<vector<int>> par,ch;
  par.assign(n,vector<int>()) ;
  ch = par;
  par[s].push_back(-1);
  ch[d].push_back(-1);

  for(int i = 0;i<n; i++){
    for(int j = 0;j<v[i].size(); j++){
      int p = i;
      int q = v[i][j].first;
      int w = v[i][j].second;
      if(dis[p]+w==dis[q]){
        par[q].push_back(p);
        ch[p].push_back(q);
      }
    }
  }

  for(int i = 0; i<par.size(); i++){
    cout<<i<<" -> ";
    for(int j = 0; j<par[i].size(); j++)
      cout<<par[i][j]<<" ";
    cout<<endl;
  }

  */
/*
*/
/*
    queue<int> q;
    q.push(s);
    vector<vector<int>> path(n-1);
    int id = 0;

    while(!q.empty()){
      int u = q.front();
      q.pop();

      for(int i = 0; i<ch[u].size(); i++){
        int child = ch[u][i];

        if(child!=-1){


        }

      }


    }
*/

}



int main(){

cin>>n>>e;
v.assign(n,vector<pp>());

while(e--){
  int a,b,c;
  cin>>a>>b>>c;
  v[a].push_back(pp(b,c));
  v[b].push_back(pp(a,c));
}
int s,d;
cin>>s>>d;

dj(s,d);









return 0;
}
