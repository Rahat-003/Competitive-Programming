#include <bits/stdc++.h>
using namespace std;
int main(){
int a;
cin>>a;
vector<int>v;
while(a--){
    int b;cin>>b;
    v.push_back(b);
}
vector<int> w;
for(int i=0;i<v.size();++i){

   int c= count(v.begin(),v.end(),v[i]);
   if(v[i]!=0){
   printf("(%d,%d) ",v[i],c);
    v[i]=0;
   }
}


return 0;
}
