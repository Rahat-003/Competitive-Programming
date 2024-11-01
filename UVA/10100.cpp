#include <bits/stdc++.h>
using namespace std;
vector<string> p,q,a,b;
#define mx 1003
int ar[mx][mx];
void word(string s, vector<string> &v){

  s.insert(0," ");
  s.push_back(' ');
  string t;

  for(int i=0;i<s.size(); ++i){
    char c = s[i];
    int d = c - '0';
    if( ( c>=65 && c<=90) || (c<=122 && c>=97 ) ||(d>=0 && d<10) ){
      t.push_back(c);
    }
    else {
    if(t.size())  v.push_back(t);
      t = "";
    }
  }
}

int lcs(int x,int y){
  if(x==p.size() || y==q.size())  return 0;
  if(ar[x][y]!=-1)  return ar[x][y];
  if(p[x]==q[y]){
    ar[x][y] = 1+ lcs(x+1,y+1);
  }
  else {
    int d = lcs(1+x,y);
    int e = lcs(x,1+y);
    ar[x][y] = max(d,e);
  }
  return ar[x][y];


}


int main(){
//  freopen("tst.txt","r",stdin);

string s,t;
int tc = 0;


string sp = "";
while(getline(cin,s)){
//  cin.ignore();
  getline(cin,t);
  tc++;
  a.push_back(s);
  b.push_back(t);
}
  int u = tc;
  stringstream ss;
  ss<<u;
  string y = ss.str();
int m = 10,g=1;

  for(int i = 1;i<y.size();++i)
    sp.push_back(' ');

  for(int i=0;i<tc;++i){
  string ss = a[i], tt = b[i];
  word(ss,p);
  word(tt,q);
  memset(ar,-1,sizeof ar);
  int ans = lcs(0,0);
//  cout<<ans<<endl;
  p.clear();
  q.clear();

  if(i+1==m){
    sp = sp.substr(g);
    m*=10;
    g++;
  }
  cout<<sp;

  if( !ss.size() || !tt.size() ) printf("%d. Blank!\n",i+1);
  else printf("%d. Length of longest match: %d\n",i+1,ans);


  }


return 0;
}
