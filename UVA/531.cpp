#include <bits/stdc++.h>
using namespace std;
#define mx 105
vector<string> u,v;
vector<vector<int>> ar;

void word(string s, vector<string> &x){
  string a;
  for(int i=0;i<s.size();++i){
    if(s[i]!=' ' && s[i]!='#')  a.push_back(s[i]);
    else{
      if(a.size())  x.push_back(a);
      a = "";
    }
  }
}


void lcs(){

    ar.assign(mx,vector<int>(mx,0) );

  vector<string> w;

  for(int i=1;i<=u.size();++i){
    for(int j=1;j<=v.size();++j){
      if(u[i-1]==v[j-1])  ar[i][j] = 1+ar[i-1][j-1];
      else
        ar[i][j] = max(ar[i-1][j],ar[i][j-1]);

    }
  }

  int i=u.size(), j = v.size();
  while(i>0 && j>0){
    if(u[i-1]==v[j-1]){
      w.push_back(u[i-1]);
      i--;  j--;

    }
    else if(ar[i-1][j]>ar[i][j-1])  i--;
    else j--;

  }
  reverse(w.begin(),w.end());
  for(int i=0;i<w.size();++i){
    cout<<w[i];
    if(i!=w.size()-1) cout<<" ";
  }
  cout<<endl;

  for(int i=0;i<ar.size();++i)
    ar[i].clear();


}

int main(){
//  freopen("tst.txt","r",stdin);
string s,t;
int cnt = 0;
while( true ){
    getline(cin,s);
    if(!s.size()) break;

  if(s[0]=='#'){
    cnt++;
  if(cnt%2==0) {
    word(t,v);
    t="";
    lcs();
    u.clear();
    v.clear();
  }
  else{
    word(t,u);
    t="";
  }

  }
  else{
    s.push_back(' ');
    t.append(s);
  }
}


return 0;
}
