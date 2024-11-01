#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int>::iterator it;
int n,e;

vector<vector<int> >graph;

bool vis[1001];
void add(int u,int v){

  graph[u].push_back(v),graph[v].push_back(u);
}
void rmv(int u,int v){
it  i=find(graph[u].begin(),graph[u].end(),v);
*i=-1;
it j=find(graph[v].begin(),graph[v].end(),u);
*j=-1;

}
int dfs(int u){
int c=1;
for(it v:graph[u])
  if(v!=-1&&!vis[v])
    c+=dfs(v);
    return c;

}

bool valid(int u,int v){
  int cnt=0;
  for(it i:graph[u])
    if(i!=-1)
      cnt++;
      if(cnt==1)
        return 1;
  fill(vis,vis+n,0);
  int c1=dfs(u);
  fill(vis,vis+n,0);
  rmv(u,v);
  int c2=dfs(u);
  add(u,v);
  return(c1>c2)?0:1;

}

void print(int u){

  for(it v:graph[u]){

    if(v!=-1&&valid(u,v)&&e){
      printf("%d -> %d ",u,v);
      e--;
      rmv(u,v);
    }
  }
}

void eulerian(){
int cnt=0;
int u=0;
  for(int i=0;i<n;i++)
    if(graph[i].size()&1){
      cnt++;
      u=i;
    }
    if(cnt>2)
      {
        printf("not eulerian\n" );
        return;
      }
      print(u);

}

int main(int argc, char const *argv[]) {

scanf("%d %d",&n,&e );
int a,b;
graph.assign(n+1,vector<int>());
for(int i=0;i<e;i++){

  scanf("%d %d",a,b );
  add(a,b);
}
  eulerian();
  return 0;
}
