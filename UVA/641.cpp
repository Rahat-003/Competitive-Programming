#include <bits/stdc++.h>

using namespace std;

map<char,int> mp;
map<int,char> np;

int m(int a,int b){
  if(a<0){
    while(a<0)  a+=b;
  }
  return a%b;

}

int main(){

int k;
for(int i = 0;i<26;i++)
  mp['a'+i] = i+1;

mp['_'] = 0;
mp['.'] = 27;

for(auto it = mp.begin();it!=mp.end(); it++){
  np[it->second] = it->first;
}


while(cin>>k){
  if(!k)  break;
  string s;
  cin>>s;
  vector<int> v(s.size(),-1);
  for(int i=0;i<s.size(); i++){
    char c = s[i];
    int c_code = mp[c];
    int id = (k*i)%s.size();

    for(int j=0;j<28;j++){
      if( m(j-i,28) == c_code){
        v[id] = j;
      break;
      }
    }


  }
  for(int i=0;i<v.size();i++)
    cout<<np[v[i]];

  cout<<endl;

}



return 0;
}
