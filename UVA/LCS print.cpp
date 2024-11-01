#include <bits/stdc++.h>
using namespace std;
string s,t,u;
//vector<bool> S,T;
vector<vector<int>> v;
#define mx 1003

int lcs(int x,int y){
  if ( x==s.size() || y==t.size() )  return 0;
  if ( v[x][y]!=-1 )  return v[x][y];

  if ( s[x]==t[y] )
    v[x][y] = 1+lcs(1+x,1+y);

  else v[x][y] = max(lcs(1+x,y),lcs(x,1+y));

  return v[x][y];
}

string func(){
  string x;
  int i=s.size(), j=t.size();
  while(i>0 && j>0){

    if(s[i-1]==t[j-1]){
//      w[a-1] = s[i-1];
      x.push_back(s[i-1]);
      i--;  j--;

      }
    else if (v[i-1][j] > v[i][j-1]) i--;
    else j--;

  }
  reverse(x.begin(),x.end());
return x;
}


int main(){

cin>>s>>t;
v.assign(mx,vector<int>(mx,-1));

int ans = lcs(0,0);

//reverse(u.begin(),u.end());
//cout<<ans<<endl<<u<<endl;

string x = func();
cout<<x<<endl;



return 0;
}
