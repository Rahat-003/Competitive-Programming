#include <bits/stdc++.h>
using namespace std;
string num,ltr;
double f(string s){
  string t; double d;
  for(int i=0;i<s.size();++i){
  auto it=find(num.begin(),num.end(),s[i]);
  if(it!=num.end()) t.push_back(s[i]);
  else {
    d = atof(t.c_str());
  if(s[i]=='m')
    d*= .001;
  if(s[i]=='M')
    d*=1000000;
  if(s[i]=='k')
    d*=1000;

  break;
  }
  }
  return d;
}


int main(){
//  freopen("tst.txt","r",stdin);
  for(int i=0;i<=9;++i){
    ltr.push_back('0'+i);
    num.push_back('0'+i);
  }
  num+=".";
  ltr+="AVWmkM.";


int t;
cin>>t;
cin.ignore();
bool fl = false;
for(int tc = 1;tc<=t;++tc){

  string s;
  getline(cin,s);
  string unit;
  vector<char> g;
  vector<string> h;
  for(int i=0;i<s.size();++i){
    if(s[i]=='='){
      g.push_back(s[i-1]);
      string e;
    for(int j = i+1;j<s.size();++j){
    auto it = find(ltr.begin(),ltr.end(),s[j]);
    if(it==ltr.end()){
      e=s.substr(i+1,j-i-1);
      h.push_back(e);
      break;
    }
  }
    }
  }
  map<char,double> l;
  for(int i=0;i<h.size();++i){
    double d = f(h[i]);
    l[g[i]] = d;
  }
  double ans;
  char w;
  string z;
  if( (g[0]=='U' && g[1]=='I') || (g[1]=='U' && g[0]=='I')  ){
      ans = l['U']*l['I'];
      z = "P=";
      w = 'W';
  }
  else if( (g[0]=='U' && g[1]=='P') || (g[1]=='U' && g[0]=='P') ){
    ans = l['P']/l['U'];
    z = "I=";
    w='A';
  }
  else if( (g[0]=='I' && g[1]=='P') || (g[1]=='I' && g[0]=='P') ){
    ans = l['P']/l['I'];
    z = "U="; w = 'V';
  }

  printf("Problem #%d\n",tc);
  cout<<z<<fixed<<setprecision(2)<<ans<<w<<endl;
  cout<<endl;
//  cout<<l['P']<<endl;
}



return 0;
}
