#include <bits/stdc++.h>
using namespace std;
int n,e;
#define inf 1e9
vector<vector<int>> graph,nxt;

void fw(){
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(graph[i][j]> graph[i][k]+graph[k][j]){
                    //  graph[i][j] = graph[i][k] + graph[k][j];
                    nxt[i][j] = nxt[i][k];
                }
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j] );
            }
        }
    }
}

void print_path(int s,int d){
  while(true){
      if(nxt[s][d]==-1){
        cout<<-1;
        break;
              }

  cout<<s<<" ";
  if(s==d)  break;
  s = nxt[s][d];

    }
}

int main(){

cin>>n>>e;

graph.assign(n,vector<int>(n,0));
nxt.assign(n,vector<int>(n,-1));

for(int i=0;i<n;++i){
  for(int j=0;j<n;++j){
    if(i==j){
      graph[i][j] = 0;
      nxt[i][j] = i;
}
    else graph[i][j] = inf;
  }
}

while(e--){
  int a,b,c = 1;
//  cin>>a>>b>>c;
    cin>>a>>b;
  //if(c<graph[a][b]){
  graph[a][b] = c;
  graph[b][a] = c;
  nxt[a][b] = b;

//}

}

fw();

cout<<endl;

for(int i=0;i<n;++i){
  for(int j=0;j<n;j++)
  if(graph[i][j]!=inf)  cout<<graph[i][j]<<" ";
  else cout<<"INF ";

  cout<<endl;
}
cout<<endl;

int s,d;
while(cin>>s>>d){
  cout<<"path is ";
  print_path(s,d);
  cout<<endl;
  cout<<"cost is "<<graph[s][d]<<endl;
}

return 0;
}
