#include <bits/stdc++.h>
using namespace std;
    vector<vector<int>> graph;
int r,c,sz;
    int cnt=0;
string dir = "NLSO";

int mod(int a){
while(a<0)
  a+=4;
  a%=4;
  return a;
}
int dx(int x,int y, char ch){

if(x-1<r && x-1>=0){
  if(ch=='N' && graph[y][x-1]!=0){
  if(graph[y][x-1]== 2){  cnt+=1;
    graph[y][x-1] = 1;
  }
    x-=1;
  }
}
if(x+1<r && x+1>=0){
  if(ch=='S' && graph[y][x+1]!=0){
    if(graph[y][x+1]== 2){ cnt+=1;
    graph[y][x+1] = 1;
    }
    x+=1;
  }
}
  return x;
}

int dy(int x,int y, char ch){
if(y+1<c && y+1>=0){
  if(ch=='L' && graph[y+1][x]!=0){
    if(graph[y+1][x]== 2){ cnt+=1;
    graph[y+1][x] = 1;
    }
    y+=1;
  }
}

if(y-1<c && y-1>=0){
  if(ch=='O' && graph[y-1][x]!=0){
    if(graph[y-1][x]== 2) {
    cnt+=1;
    graph[y-1][x] = 1;
    }
    y-=1;
  }
}

return y;
}
int main(){
 //freopen("11831.txt","r",stdin);
while(cin>>r>>c>>sz){

    graph.assign(c,vector<int>(r,0));

    cnt=0;
    if(!r && !c && !sz) break;
    int ix,iy,sum;
    string s;
    char ch;
    int pp=0;
    for(int i=0;i<r;i++){
      cin>>s;
      for(int j=0;j<c;j++){
        if(s[j]=='N' || s[j]=='S'|| s[j]=='L'|| s[j]=='O'){
          ix = i;
          iy = j;
          ch = s[j];
          sum = dir.find(ch);
          graph[j][i] = 5;
        }
        if(s[j]=='#')   graph[j][i]=  0;
        if(s[j]=='.')   graph[j][i]=  1;
        if(s[j]=='*') {  graph[j][i]=  2;
        pp+=1;
        }
      }
    }
   string I;  cin>>I;
    for(int i=0;i<I.size();i++){
      if(I[i]=='D')   sum+=1;
      if(I[i]=='E')   sum-=1;
      sum = mod(sum);
      ch = dir[sum];
      if(I[i]=='F'){
        ix = dx(ix,iy,ch);
        iy = dy(ix,iy,ch);
      }
    }
cout<<cnt<<endl;
int p=0;

for(int i=0;i<c;i++)
  graph[i].clear();
}
return 0;
}
