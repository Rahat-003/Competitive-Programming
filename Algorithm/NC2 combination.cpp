
#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> v;
int a;
while(cin>>a){
for(int i=0;i<a;i++)
  v.push_back(i);

  int c=0, cnt=0;;
  while(1){
      if(c==v.size()) break;
    for(int i=c+1;i<v.size();++i){
      cout<<v[c]<<" "<<v[i]<<endl;
      cnt++;
    }
    c+=1;
  }
cout<<cnt<<endl;
v.clear();
}
return 0;
}
