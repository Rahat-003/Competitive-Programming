
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph,v;
int n;

int ans(int s,int d,int k){
  int path[n][n][k+1];

  for(int e = 0;e<=k;e++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        path[i][j][e] = 0;
        if(e==0 && i==j)  path[i][j][e] = 1;
        if(e==1 && graph[i][j]) path[i][j][e] = 1;

        if(e>1){
          for(int m = 0; m<n; m++){
            if(graph[i][m] && graph[m][j])
              path[i][j][e] += path[i][m][e-1];
          }
        }
      }
    }
  }
  return path[s][d][k];
}

int main(){
int e;

cin>>n>>e;
v.assign(n,vector<int>());
graph.assign(n,vector<int>(n,0));

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  graph[a][b] = 1;
}

int s,d,edge;
cin>>s>>d>>edge;

int numberOfPath = ans(s,d,edge);

cout<<numberOfPath<<endl;



return 0;
}
