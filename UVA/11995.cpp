#include <bits/stdc++.h>
using namespace std;

int main(){

int n;
while(cin>>n){
  stack<int> stk;
  queue<int> q;
  priority_queue<int> pq;
  vector<int> d,e,f,clct;
  while(n--){
    int a;  int b;
    cin>>a>>b;
    if(a==1){
      stk.push(b);
      q.push(b);
      pq.push(b);
    }
    else if(a==2 ){
      clct.push_back(b);

      if(!q.empty()){
      d.push_back(stk.top());
      e.push_back(q.front());
      f.push_back(pq.top());
      stk.pop();  q.pop();  pq.pop();
//      break;
    }

    }
  }
  if(d==clct || e==clct || f==clct ){
  if( (clct==d && clct==e) || (clct==d && clct==f) || (clct==e && clct==f) )
    cout<<"not sure"<<endl;
  else if(d==clct)  cout<<"stack"<<endl;
  else if(e==clct)  cout<<"queue"<<endl;
  else if(f==clct)  cout<<"priority queue"<<endl;
  }
  else cout<<"impossible"<<endl;
//cout<<d<<" "<<e<<" "<<f;

}

return 0;
}

