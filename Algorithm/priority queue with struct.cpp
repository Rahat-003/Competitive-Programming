#include <bits/stdc++.h>
using namespace std;

struct node{
  int u,v;
  bool operator() (const node& a, const node& b){
  return a.u>b.u;
  }
};

int main(){
priority_queue<node,vector<node>,node> pq;
node m,n;
m.u = 1;
m.v = 2;
n.u = 2;
n.v = 1;
pq.push(m);
pq.push(n);
while(!pq.empty()){
  cout<<pq.top().u<<" "<<pq.top().v<<endl;
  pq.pop();
}




return 0;
}
