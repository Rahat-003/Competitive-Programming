
#include <bits/stdc++.h>
using namespace std;

bool kmp(string s, string p){
  int sz = s.size(), pz = p.size();
  int ar[pz];
  memset(ar,0,sizeof ar);
  int i=0,j=1;
  while(j<pz){
    if(p[i]==p[j]){
      i++;
      ar[j] = i;
      j++;
    }
    else{
      if(i!=0) i = ar[i-1];
      else{
        ar[j] = 0;
        j++;
      }
    }
  }

  int ii=0,jj=0;
  while(jj<sz){
    if(s[jj]==p[ii]){
      ii++;
      jj++;
    }
    if(ii==pz)  return true;
    else if(s[jj]!=p[ii]){
      if(ii!=0) ii = ar[ii-1];
      else jj++;
    }
  }


return false;
}


int main(){

int tc;
cin>>tc;
while(tc--){
  string s;
  cin>>s;
  int q;  cin>>q;
  while(q--){
    string t;
    cin>>t;
    if(kmp(s,t))  puts("y");
    else puts("n");
  }
}

return 0;
}
