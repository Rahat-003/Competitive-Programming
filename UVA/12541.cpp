#include <bits/stdc++.h>
using namespace std;
typedef pair<int,string> pp;
typedef pair<int,pp> ppp;
typedef pair<int,ppp> pppp;
vector<pppp> v;
int main(){
int t;
cin>>t;
while(t--){
  string n;
  int d,m,y;
  cin>>n>>d>>m>>y;
  v.push_back(pppp(y,ppp(m,pp(d,n))));
}
sort(v.begin(),v.end());
cout<<v[v.size()-1].second.second.second<<endl;
cout<<v[0].second.second.second<<endl;
v.clear();



return 0;
}
