
#include <bits/stdc++.h>
using namespace std;

vector<string> v,w;


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
      int cnt=0,x=0;

    for(int i=0;i<s.size();++i){
      if(s[i]!=t[i]){
      cnt++;
      }
      if(cnt>1) return false;
    }
    if(cnt==1 || !cnt)  return true;
  }

  if(sz<tz) return check(s,t);
  else return check(t,s);

}



int main(){

  //freopen("tst.txt","r",stdin);

int tc;
cin>>tc;
bool fl = false;

while(tc--){
  cin.ignore();
  if(fl)  cout<<endl;

  unordered_map<string,bool> vis;
  string s,t;
  while(getline(cin,s)){
    if(s[0]=='#') break;
    v.push_back(s);
    vis[s] = true;
  }
  while(getline(cin,t)){
    if(t[0]=='#') break;
    w.push_back(t);
  }


  for(int i=0;i<w.size();i++){
    string r = w[i];
    cout<<r;
    if(vis[r]){
      cout<<" is correct\n";
      continue;
    }
    cout<<":";
    for(int j=0;j<v.size();++j){
      string t = v[j];
      int tsz = t.size(), rsz = r.size();
      if(rsz-1==tsz || rsz==tsz || rsz+1==tsz){
          if(f(r,t))  cout<<" "<<t;
      }
    }
  cout<<endl;

  }
  v.clear();  w.clear(); vis.clear();
  fl=true;


}


return 0;
}
