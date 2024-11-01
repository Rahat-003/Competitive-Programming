#include <bits/stdc++.h>
using namespace std;
vector<int> p,q;
int ar[253][253];
#define mx 255*255
int lcs(int x,int y){
  if(x==p.size() || y==q.size())  return 0;

  if(ar[x][y]!= -1)  return ar[x][y];

  if(p[x]==q[y])
    return 1+lcs(1+x,1+y);
  else{
    int m = lcs(1+x,y);
    int n = lcs(x,1+y);
    ar[x][y] = max(m,n);
  }
  return ar[x][y];
}



int main(){
  freopen("tst.txt","r",stdin);
int t;
cin>>t;
for(int tc = 1;tc<=t;++tc){
  int n,w,e;
  cin>>n>>w>>e;
  w++;  e++;
  memset(ar,-1,sizeof ar);
  p.assign(w+3,-1);
  q.assign(e+3,-2);

  for(int i=0;i<w;++i){
    int a;  cin>>a; p[i] = a;
  }
  for(int i=0;i<e;++i){
    int a;  cin>>a; q[i] = a;
  }
  int ans = lcs(0,0);
  printf("Case %d: %d\n",tc,ans);
  p.clear();
  q.clear();
}


return 0;
}
