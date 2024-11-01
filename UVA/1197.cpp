#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ar,child;
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

int main(){
  freopen("tst.txt","r",stdin);
int n,e;
while(scanf("%d %d",&n,&e)){
  if(!n && !e)  break;
  child.assign(n,1);
  int cnt = 0;
  for(int i=0;i<n;++i)
    ar.emplace_back(i);

  vector<int> sus;
  while(e--){
    vector<int> v;
    int c,d;
    scanf("%d",&c);
    while(c--){
      scanf("%d",&d);
      v.emplace_back(d);
    }
    auto it = find(v.begin(),v.end(),0);
    if(it!=v.end()){
      for(int i=0;i<v.size();++i)
        if(v[i]!=*it)
        sus.emplace_back(v[i]);
    }
    else{
      int x = v[0];
      int rx = f(x);
      for(int i=0;i<v.size();++i){
        int y = v[i];
        int ry = f(y);
        if(rx!=ry){
          child[rx]+=child[ry];
//          child[ry] = child[rx];
          ar[ry] = rx;
        }

      }

    }
  }
  if(sus.size()){
    int px = f(0);
    for(int i=0;i<sus.size();++i){
      int y = sus[i];
      int py = f(y);
      if(px!=py){
        child[px]+=child[py];
        ar[py] = px;
      }
    }


    }
 /*
  for(int i=0;i<child.size();++i){
    if(child[i]>cnt)
      cnt = child[i];
  }
  cout<<cnt<<endl;
  */
  printf("%d\n",child[0]);
  ar.clear(); child.clear();

}



return 0;
}
