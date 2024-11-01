#include <bits/stdc++.h>
using namespace std;

struct node{
  int a,b,c;
  node(int x,int y,int z){
    a = x;
    b = y;
    c = z;
  }

};


int n,e;;

vector<int> dist;
//vector<vector<int>> cost;

vector<node>v;


void bf(int s){
  dist[s] = 0;

  for(int i = 1; i<n; i++){
    for(int j = 0;j<v.size();j++){
      int a = v[j].a;
      int b = v[j].b;
      int c = v[j].c;

///      if( dist[a] + c < dist[b] ) dist[b] = dist[a] + c;

      dist[b] = min(dist[a]+c,dist[b]);

    }
  }

  for(int i = 0;i<v.size(); i++){
    node x = v[i];
    int a = x.a;
    int b = x.b;
    int c = x.c;

    if( dist[a]+c<dist[b] ) {
      puts("negative cycle");
      break;
    }

  }

}

int main(){
cin>>n>>e;

dist.assign(n,1e7);

for(int i = 0;i<e;i++){
  int a,b,c;
  cin>>a>>b>>c;
  v.push_back(node(a,b,c));
}

int s;
cin>>s;

bf(s);

int d;
while(cin>>d){
  cout<<dist[d]<<endl;

}




return 0;
}

