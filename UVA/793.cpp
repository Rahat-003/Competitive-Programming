#include <bits/stdc++.h>
using namespace std;
vector<int> ar;
int suc,unsuc;
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];

}

int main(){

int t;
cin>>t;
//d=n;
bool fl = false;
for(int T=0;T<t;++T){
int n,d;
    if(fl) cout<<endl;
  fl = true;
    suc = 0;
    unsuc = 0;
  cin>>n;
  for(int i=0;i<=n;++i)
    ar.push_back(i);
  cin.ignore();
  string s;
  while(true){
  getline(cin,s);
    if(!s.size()){
    //d = atoi(s.c_str());
    ar.clear();

    cout<<suc<<","<<unsuc<<endl;
    break;
    }
    string t;
    t = s.substr(1);
    stringstream ss(t);
    vector<int> v;
    int p;
    while(ss>>p){
//        cout<<p<<" ";
      if(p)
        v.push_back(p);
    }
//cout<<endl;
    int a,b;
    a = v[0], b = v[1];
    char c = s[0];
    if(c=='c'){
      int pa = f(a);
      int pb = f(b);
      if(pa!=pb){
        ar[pb] = pa;
      }
    }
    else{
      int pa = f(a);
      int pb = f(b);
      if(pa==pb)
        suc+=1;
      else unsuc+=1;
    }

  }


}






return 0;
}
