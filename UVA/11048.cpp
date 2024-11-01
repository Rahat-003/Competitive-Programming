#include <bits/stdc++.h>
using namespace std;


bool check(string s,string t){

  int sz = s.size(), tz = t.size();
    int cnt=0,x = 0;
  for(int i=0;i<t.size();++i){
    if(s[x]!=t[i])  cnt++;
    else x++;
    if(cnt>1) return false;
  }
  if(cnt==1 || !cnt)  return true;

}

bool f(string s,string t){

  int sz = s.size(), tz = t.size();

  if(sz==tz){
      int cnt=0,x=0, adj=0;
  s.push_back(' ');
  t.push_back(' ');
    for(int i=0;i<s.size();++i){

      if(s[i]!=t[i] && s[i+1]==t[i] && s[i]==t[i+1]){
        i+=1;
        adj++;

      continue;
      }

      if(s[i]!=t[i])  cnt++;

    }

    if(cnt && adj)  return false;
    if(cnt<=1)  return true;
    if(cnt>1)  return false;
  }

  if(sz<tz) return check(s,t);
  if(sz>tz) return check(t,s);

}


int main(){

unordered_map<string,bool> vis;

vector<string> u,v;
int n;  cin>>n;
while(n--){
  string s;
  cin>>s;
  vis[s] = true;
  u.push_back(s);
}
int e;  cin>>e;
while(e--){
  string s; cin>>s;

  bool fl = false;
  cout<<s<<" is ";

  if(vis[s])  printf("correct\n");
  else{
    for(int i=0;i<u.size();++i){
      string t = u[i];
      int tz = t.size(), sz = s.size();
      if(tz==sz || tz-1==sz || tz+1==sz){
        if(f(s,t)){
          cout<<"a misspelling of "<<t<<endl;
          fl = true;
        break;
        }

      }
    }
  }
  if(!fl && !vis[s])  cout<<"unknown\n";

}







return 0;
}
