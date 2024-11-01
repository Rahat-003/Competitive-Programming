#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
int tc;
cin>>tc;
ll total =0;
while(tc--){
  string s,t;
  ll a;
  cin>>s;
  if(s=="donate"){
    cin>>a; total+=a;
  }
  else cout<<total<<endl;

}

return 0;
}
