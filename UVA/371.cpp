#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<ull> ar;

ull id = 0;

ull func(ull a,ull b ){

  ull ans = 0;



  for(ull i = a; i<=b;i++){
    ull cnt = 0, p = i;

    while(true){
      if(p&1) p = 3*p+1;
      else p/=2;
      cnt++;
      if(p==1)  break;
    }
  if(cnt>ans){
  id = i;
  ans = cnt;
  }

  }

return ans;

}

int main(){


ull a,b;

while(cin>>a>>b){
  if(!a && !b)  break;
  if(a>b) swap(a,b);

  ull ans = func(a,b);

  printf("Between %llu and %llu, %llu generates the longest sequence of %llu values.\n",a,b,id,ans);

}

return 0;
}

