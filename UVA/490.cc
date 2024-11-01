
#include <bits/stdc++.h>
using namespace std;
vector<string> v;


int main(){

string s;
int mx=0;
while(getline(cin,s)){
    if(!s.size()) break;
    v.push_back(s);
    if(s.size()>mx) mx = s.size();
}

for(int i=0;i<mx;++i){

  for(int j=v.size()-1; j>=0; --j){
      string s = v[j];
  if( i<s.size() )
    cout<<s[i];
  else cout<<' ';
  }
cout<<endl;
}



return 0;
}
