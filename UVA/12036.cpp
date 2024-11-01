#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
int t;  cin>>t;
for(int tc = 1;tc<=t;++tc){

  int n;
  cin>>n;
  v.assign(103,0);
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      int a;
      cin>>a;
      v[a]++;
    }
  }
  bool ans = true;
  for(int i=0;i<v.size();++i){
    if(v[i]>n){
      ans = false;
      break;
    }
  }
  printf("Case %d: ",tc);
  if(ans) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}


return 0;
}
