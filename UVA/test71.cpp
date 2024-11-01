#include <bits/stdc++.h>
using namespace std;

int a,b;
int ar[53][53];
int br[53][53];
string dir= "NESW";

int dx(int sum,int x){
  if(dir[sum]=='E')
    x+=1;
  else if(dir[sum]=='W')
    x-=1;
  return x;
}

int dy(int sum,int y){
  if(dir[sum]=='N')
    y+=1;
  else if(dir[sum]=='S')
    y-=1;

  return y;

}
main(){
cin>>a>>b;
  int x,y;
  char s;
  memset(ar,false,sizeof ar);
  for(int i=0;i<=a;i++)
    for(int j=0;j<=b;j++){
    ar[i][j] = true;
    br[i][j] = 0;
    }

while(cin>>x>>y>>s){
  string line;
  cin.ignore();
  getline(cin,line);

    int length = line.size(), sum = dir.find(s),nx=0,ny=0,flag=1,cnt=0,ix=x,iy=y;

    for(int i = 0; i<length; i++){

    if(line[i]=='L') sum-=1;

      else if(line[i]=='R') sum+=1;

      else if(line[i]=='F'){
        while(sum<0) sum+=4;
        sum%=4;
        if(ar[nx][ny]){
        nx = dx(sum,x);
        ny = dy(sum,y);
        }
        if(ar[nx][ny]){
        x = nx;
        y = ny;
      }
      }
    }
  while(sum<0) sum+=4;
  sum%=4;
  if(flag){
    cout<<nx<<" "<<ny<<" "<<dir[sum]<<endl;
  }
  else cout<<x<<" "<<y<<" "<<dir[sum]<<" LOST"<<endl;

//  cout<<br[x][y]<<endl;
}

}

