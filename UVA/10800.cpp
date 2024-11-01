#include <bits/stdc++.h>
using namespace std;


vector<string> v;

char func(char c){
  if(c=='R')  return '/';
  if(c=='F')  return '\\';
  if(c=='C')  return '_';
}

void f(string s){
  for(int j=0;j<v.size() ; ++j){

  for( int i=0;i<s.size(); ++i ){
      v[j].push_back(' ');
  }
}

}
string cut(string t){
  int i;
  for(i=t.size()-1; i>=0; --i)
    if(t[i]!=' ')  break;


  string s = t.substr(0,i+1);
  return s;
}




int main(){
  /*
  freopen("tst.txt","r",stdin);
  freopen("t.txt","w",stdout);
*/
int t;
cin>>t;
for(int tc = 1;tc<=t;++tc)
{
  string s;
  cin>>s;
  int pos = 0, neg = 0, tot = 0;

  string last( s.size()+2, '-');
  last.insert(0,"+");
 // s.insert(0," ");
  bool fl = false;
  int lvl=0;
  for(int i=0; i<s.size(); ++i){
    if(s[i]=='R') tot++;
    if(s[i]=='F') tot--;
    if(tot>pos) pos = tot;
    if(tot<neg) neg = tot;
  }


  string same = "| ";
  int sz = pos - neg ;

  for(int i=0;i<sz;++i)
    v.push_back(same);

  f(s);
  int nn = -neg, cnt = 0;


  for(int i=0;i<s.size(); ++i){
    char c = s[i];

  if(c=='R'){
    v[nn+cnt][i+2] = func(c);
    cnt++;
  }
  if(c=='F'){
    cnt--;
    v[nn+cnt][i+2] = func(c);
  }
  if(c=='C'){

    int x = nn+cnt;
    if (x==sz){
        v.push_back(same);
      for(int k=0; k<=i+2;++k)
        v[x].push_back(' ');
    }

   v[nn+cnt][i+2] = func(c);
  }

  }
  reverse(v.begin(),v.end());

  printf("Case #%d:\n",tc);
  for(int i=0;i<v.size(); ++i){
    string s = v[i];
    s = cut(s);
    if(s=="|")  continue;
    cout<<s<<endl;
  }
  cout<<last<<endl<<endl;

v.clear();

}

return 0;
}
