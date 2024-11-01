#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<ull> ar;

ull func(ull a,ull b){

  ull ans = 0;

  if(a>b) swap(a,b);


  for(ull i = a; i<=b;i++){
    ull cnt = 1, p = i;

    while(p!=1){
      cnt++;
      if(p&1) p = 3*p+1;
      else p/=2;
    }
  if(cnt>ans) ans = cnt;

  }
return ans;

}

int main(){


ull a,b;

while(cin>>a>>b){

  ull ans = func(a,b);

cout<<a<<" "<<b<<" "<<ans<<endl;

}

return 0;
}
