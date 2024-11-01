
#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int todec(string s){
  int ans = 0;
  int sz = s.size() -1;
  for(int i=0;i<s.size(); i++){
    ans += (s[i] - '0')*pow(2,sz-i);

  }
  return ans;

}


void shift(int x,string s){
  string up = "UU", low = "LL";
  int i;
  for(i=s.size()-1; i>=0;i--){
    if(s[i]==' '){
      v[i+x] = up;
      break;
    }
}
  for(int j = i-1;j>=0; j--){
    if(s[j]==' '){
      v[j+x] = low;
      break;
    }
  }


}


void make(string l){
  for(int i = 0;i<l.size(); i++){
    string m(1,l[i]);
    v.push_back(m);
  }
}
string f(string s){
  string ans;
  for(int i=0;i<s.size();i++)
    if(s[i]!=' ') ans.push_back(s[i]);
  return ans;
}


int main(){
//freopen("tst.txt","r",stdin);

string l,u;


while(getline(cin,l)){
  getline(cin,u);
  string s;
  make(l);
  shift(0,l);
  make(u);
  shift(l.size(), u);

  while(cin>>s){
      s = f(s);
    int S = 0;
    string ans;
    for(int i=0;i<s.size(); i+=5){
      string ID = s.substr(i,5);
      int id = todec(ID);
      if(v[id+S]=="UU") {
      S=32;
      continue;
      }
      if(v[id+S]=="LL"){
      S=0;
      continue;
      }
      ans.push_back(v[id+S][0] );

    }
  cout<<ans<<endl;
  }

}

return 0;
}
