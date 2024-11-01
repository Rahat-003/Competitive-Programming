#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
int t;
cin>>t;

while(t--){
  string s;
  v.assign(10,0);
  int a;
  cin>>a;

  for(int i=1;i<=a;i++){
    stringstream ss;
    ss<<i;
    string q = ss.str();
    s.append(q);
  }

  for(int i=0;i<s.size(); i++){
    int id = s[i] - '0';
    v[id]++;
  }
  for(int i=0;i<v.size(); i++){
    cout<<v[i];
    if(i!=v.size()-1) cout<<" ";
  }
  cout<<endl;

}


return 0;
}
