#include <bits/stdc++.h>
using namespace std;

int ar[12][12];

int n;

int sum(int x,int y,int r, int c){
  int lx = x;
  int ly = y;
  int ux = c;
  int uy = r;
  int ans = 0;

  for(int i = lx; i<ux;i++){
    ans+= ar[ly][i];
  if(ly!=uy-1)  ans+= ar[uy-1][i];
  }
  for(int j = ly+1;j<uy-1;j++){
    ans+= ar[j][lx];
  if(lx!=ux-1)  ans+= ar[j][ux-1];
  }
return ans;

}

int main(){
int tc = 0;

while(cin>>n){
    if(!n)  break;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>ar[i][j];
        vis[i][j] = false;
      }
    }
    vector<int> v;


  for(int i=0;i<=n/2;i++){
     if(n%2==0 && i==n/2) continue;
      int ans = sum(i,i,n-i,n-i);
      v.push_back(ans);
    }

    printf("Case %d: ",++tc);

for(int i=0;i<v.size();i++){
  cout<<v[i];
if(i!=v.size()-1) cout<<" ";

}
cout<<endl;

  }


return 0;
}
