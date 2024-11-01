
#include <bits/stdc++.h>
using namespace std;

int main(){

vector<int> v = {1,2,3,4,5};
auto it = find(v.begin(),v.end(),99);
if(it!=v.end())
  cout<<1;
else cout<<0;


return 0;
}
