#include <bits/stdc++.h>
using namespace std;
vector<int> num = {1,2,3,4,5,6,7,8,9,0};

int main(){
int t;
cin>>t;
for(int tc = 1;tc<=t;++tc){
  string s,n,ans;
  int x;
  cin>>s;
  s.push_back('.');
  char c;

  for(int i=0;i<s.size();i++){
      int y = s[i] - '0';
    auto it = find(num.begin(),num.end(), y );
      if(it!=num.end()){
        n.push_back(s[i]);
      }
      else{
   if(i){
        x = atoi(n.c_str());
        for(int i=0;i<x;++i)
          ans.push_back(c);
        n="";
      }
      c = s[i];
    }
  }
printf("Case %d: ",tc);
cout<<ans<<endl;



}





return 0;
}
