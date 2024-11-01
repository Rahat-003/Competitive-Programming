
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;
typedef pair<int,pp> ipp;

#define mx 1000002
vector<ipp> graph;
vector<int> ar;
vector<int> v[mx];

int f(int a){
  if(ar[a]==a)  return a;
  return ar[a]=f(ar[a]);
}


int k(int &edge){
  int min_range = 0;
  edge = 0;
  for(int i=0;i<graph.size();++i){
    int px = f(graph[i].second.first);
    int py = f(graph[i].second.second);
    int pz = graph[i].first;
    if(px!=py){
    if(rand()%2)    swap(px,py);
        ar[py] = px;
        edge++;
      if(pz>min_range)  min_range = pz;

    }
  }
  return min_range;
}
/*
void dfs(int a){
  vis[a] = true;
  for(int i=0;i<v[a].size();++i){
    int child = v[a][i];
    if(!vis[child]){
      dfs(child);
    }
  }
}*/

int main(){

int n,e;

while(true){
    scanf("%d %d",&n,&e);
    if(!n && !e)   break;
    ar.clear();
    graph.clear();
    for(int i=0;i<n;++i)    v[i].clear();

    for(int i=0;i<n;++i)  ar.push_back(i);

//  vis.assign(n,false);
//  v.assign(n,vector<int> ());
    for(int i=0;i<e;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    v[a].push_back(b);
    v[b].push_back(a);
    graph.push_back(ipp(c,pp(a,b)));
  }


  /*
  dfs(0);
  int cnt = count(vis.begin(),vis.end(),false);
  if(cnt)   cout<<"IMPOSSIBLE";
  else{
    sort(graph.begin(),graph.end());
    int min_cnt = k();
    cout<<min_cnt;
  }
  cout<<endl;
  */
    sort(graph.begin(),graph.end());
    int edge,ans = k(edge);

    if(edge!=n-1) puts("IMPOSSIBLE");
    else printf("%d\n",ans);


}

return 0;
}
