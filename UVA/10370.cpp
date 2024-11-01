#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;
while(t--){
  int cs; cin>>cs;
  double tot = 0,avg;
  vector<double> v;
  for(int i=0;i<cs;++i){
    double a; cin>>a;
    tot+=a;
    v.push_back(a);
  }
  avg = tot/cs;
  double ans, cnt = 0;
  for(int i=0;i<v.size();++i){
    if(v[i]>avg)  cnt++;
  }
  ans = cnt/cs*100;

  cout<<fixed<<setprecision(3)<<ans<<"%"<<endl;
}






return 0;
}
