#include <bits/stdc++.h>
using namespace std;

int main(){

vector<int> v ={5,2,3,6,8,9,7,4,1};
sort(v.begin(),v.end(), greater<int> ());   /// default is less
for(int i=0;i<v.size();++i)
  cout<<v[i]<<" ";
cout<<endl;

vector<string> s = {"ajam","shihab","arafat","khalid","rahat"};


sort(s.begin(),s.end(),greater<string>());

for(int i=0;i<s.size();++i)
  cout<<s[i]<<" ";

return 0;
}
