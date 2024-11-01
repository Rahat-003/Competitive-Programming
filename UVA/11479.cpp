#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ll t;
cin>>t;
ll tc=0;
while(t--){
  vector<ll> v;
  tc++;
  ll b,c,d;

    for(int i=0;i<3;++i){
      ll a;
      cin>>a;
      v.push_back(a);
    }
  sort(v.begin(),v.end());
  b=v[0]; c=v[1]; d=v[2];
//  cin>>b>>c>>d;
    cout<<"Case "<<tc<<": ";
  if(b+c<=d ||(!b || !c || !d))
    printf("Invalid");

  else if(b==c && c==d && b==d)
    cout<<"Equilateral";
  else if(b!=c && c!=d && b!=d)
    cout<<"Scalene";
  else cout<<"Isosceles";



  cout<<endl;

}

return 0;
}
