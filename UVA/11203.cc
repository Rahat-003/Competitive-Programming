#include <bits/stdc++.h>
using namespace std;

bool check(string s){
  int x = 0,y=0,z=0;
  int cnt = 0;
  char c = 'M';
  int i;
  for( i=0; i<s.size(); i++){
    if(s[i]=='?')
      cnt++;
    else if(s[i]==c){
        if(!cnt)  break;
      cnt = 0;
      c='E';
    }
    else break;
  }
  //cout<<i<<endl;
  if(i!=s.size() || s[s.size()-1]!='?') return false;
  return true;
}
bool recheck(string s){
  int x=0,y=0,z=0,cnt = 0;
  char c = 'M';
  vector<int> v;
  for(int i=0;i<s.size();++i){
    char d = s[i];
    if(d=='?')
      cnt++;
    else if(d==c){
      v.push_back(cnt);
      cnt = 0;
      c = 'E';
    }
  }
  v.push_back(cnt);
  if(v[2]-v[0]==v[1]) return true;
  return false;

}



int main(){

int t;
cin>>t;
cin.ignore();
while(t--){
  string s;
  getline(cin,s);
  string ans="";
  if( check(s) ){
    if(!recheck(s))
      ans = "no-";
  }
  else ans = "no-";

  cout<<ans;
  puts("theorem");
}





return 0;
}

