
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(string s){
  vector<int> v;
  v.assign(10,0);
  for(int i=0;i<s.size(); i++){
    int x = s[i] - '0';
    v[x]++;
    if(v[x]>1)  return false;
  }
  return true;

}


int func(int a,int b){

  int cnt = 0;
  for(int i = a;i<=b;i++){
    stringstream ss;
    ss<<i;
    string s = ss.str();
    if(check(s))  cnt++;

  }
  return cnt;

}


int main(){

int a,b;

while(cin>>a>>b){
  int ans = func(a,b);
  cout<<ans<<endl;

}


return 0;
}
