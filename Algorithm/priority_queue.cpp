#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
int main(){

priority_queue<pp,vector<pp>,greater<pp> > pq;   ///or greater (reverse result)

/// pop priority queue according to first element of pair. Lowest element will be popped at last

pq.push(pp(1,2));
pq.push(pp(2,1));
while(!pq.empty()){
  cout<<pq.top().first<<" "<<pq.top().second<<endl;
  pq.pop();
}

return 0;
}
