/**
একটি ডিরেক্টেড গ্রাফে অয়লার সার্কিট থাকবে যদি গ্রাফটি কানেক্টেড হয় এবং প্রতিটি নোডের আউটডিগ্রি এবং ইনডিগ্রি সমান হয়।
একটি আনডিরেক্টেড গ্রাফে অয়লার সার্কিট থাকবে যদি গ্রাফটি কানেক্টেড হয় এবং প্রতিটি নোডের ডিগ্রী জোড় সংখ্যা হয়।
একটি ডিরেক্টেড গ্রাফে অয়লার পাথ থাকবে শুধুমাত্র যদি গ্রাফটি কানেক্টেড হয় এবং ২টি মাত্র নোডের আউটডিগ্রি এবং ইনডিগ্রির
পার্থক্য 1 হয় এবং বাকি সব নোডের আউটডিগ্রি এবং ইনডিগ্রি সমান হয়। শুরুর নোডের ক্ষেত্রে indegree = outdegree-1
 আর শেষের নোডের ক্ষেত্রে
outdegree = indegree-1 হবে
*/
//Directed Graph is either Eulerian Or Not.. No Semi (Assump)

#include <bits/stdc++.h>
using namespace std;
int n,e;
vector<vector<int>> graph,reverse_graph;
vector<bool> vis;
vector<int> indegree,outdegree;

void dfs(int a, auto &v ){
  vis[a] = true;
  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child])
      dfs(child,v);
  }
}


bool check (int a, auto &v ){
  dfs(a,v);

  for(int i=0;i<vis.size(); i++)
    if(!vis[i] && v[i].size()) return false;

  return true;
}

bool Euler_directed(int a){

  if(!check( a,graph ))  return false;
  vis.assign(n,false);

  if(!check( a,reverse_graph)) return false;

  for(int i=0;i<n;i++)
    if(indegree[i]!=outdegree[i]) return false;

  return true;

}


int main(){

cin>>n>>e;

graph.assign( n,vector<int>() );

reverse_graph = graph;

indegree.assign(n,0);
outdegree = indegree;

vis.assign(n,false);

while(e--){

  int a,b;
  cin>>a>>b;

  graph[a].push_back(b);
  reverse_graph[b].push_back(a);

  outdegree[a]++;
  indegree[b]++;

}

int i;

for(i=0;i<n;i++){
  if(graph[i].size()) break;
}

bool E = Euler_directed(i);

if(E) puts("Eulerian graph");
else  puts("Not Eulerian graph");


return 0;
}
