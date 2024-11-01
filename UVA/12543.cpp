#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> pp;
vector<string> v;

void word(string s){
  string a;
  s.push_back(' ');

  for(int i=0;i<s.size();++i){
    int d = s[i];
    char c = d;
    if ((d>=65 && d<=90)|| (d>=97 && d<=122) || c == '-' )
      a.push_back(c);

    else{
      if(a.size() && a!="E-N-D")  v.push_back(a);
      a="";
    }

  }

}



int main(){

//freopen("tst.txt","r",stdin);


string s;
while(getline(cin,s)){
  int sz = s.size()-1;
    string e;
    if(sz-4>=0) e = s.substr(sz-4);

  word(s);

    if(e=="E-N-D")  break;
}
int f = 0;
string ans;
for(int i=0;i<v.size();++i){
  string b = v[i];
  if(b.size()>f)  {
      f = b.size();
  ans = b;
}
}

transform(ans.begin(),ans.end(),ans.begin(),::tolower);
cout<<ans<<endl;



return 0;
}
