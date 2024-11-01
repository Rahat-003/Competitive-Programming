#include <bits/stdc++.h>
using namespace std;

int main(){
int t, tc = 0;
cin>>t;
while(t--){
  vector<int> v;
  int a;
  cin>>a;
  int id = a/2;
  while(a--){
    int b;  cin>>b;
    v.push_back(b);
  }
  sort(v.begin(),v.end());
  printf("Case %d: %d\n",++tc,v[id]);

}

return 0;
}
