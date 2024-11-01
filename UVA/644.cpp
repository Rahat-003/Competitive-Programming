#include <bits/stdc++.h>
using namespace std;

  vector<string> v;

bool f(string s,string t){
  if(t.size()<s.size())
    swap(s,t);
  int i;
  int sz = s.size()-1;
  for( i=0;i<s.size();++i)
    if(s[i]!=t[i])  break;

  if(i==s.size() && s[sz]==t[sz]) return false;
  return true;
}


bool check(){
  for(int i=0;i<v.size()-1;++i){
      string s = v[i];
    for(int j=i+1;j<v.size();++j){
      string t = v[j];
      if(!f(s,t))
        return false;
    }


  }
return true;
}


int main(){
 //freopen("tst.txt","r",stdin);
string s;
int tc=0;
while(cin>>s){
 if(s!="9") v.push_back(s);

if(s=="9"){
  ++tc;
  bool m = check();

  if(!m)
    printf("Set %d is not immediately decodable\n",tc);

    else
      printf("Set %d is immediately decodable\n",tc);

/*
  for(int i=0;i<v.size()-1;++i)
    cout<<v[i]<<" ";
  cout<<endl;
  */
v.clear();
}
}

return 0;
}
