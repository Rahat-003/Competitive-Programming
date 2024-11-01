#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  while(cin>>a){
    if(!a)  break;
    vector<double> v,mm,nn;
    v.clear();    mm.clear();   nn.clear();
    int b;  cin>>b;

    while(a--){
      double m; cin>>m;
      mm.push_back(m);
    }
    while(b--){
      double n; cin>>n;
      nn.push_back(n);
    }
    for(int i=0;i<mm.size();i++){
      for(int j=0;j<nn.size();++j){
        v.push_back(nn[j]/mm[i]);
      }
    }
    sort(v.begin(),v.end());
    double f = 0;
    for(int i=1;i<v.size();i++){
      double s = v[i]/v[i-1];
      if(s>f)
        f=s;
    }
    cout<<fixed<<setprecision(2)<<f<<endl;
  }



return 0;
}
