#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
while(cin>>n){
vector<int> v;
set<int> s;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    v.push_back(a);
    s.insert(a);
}
vector<int> dif;
v.push_back(0);
sort(v.begin(),v.end());
for(int i=1;i<v.size();i++){
    if(v[i-1]!=v[i]){
        dif.push_back(count(v.begin(),v.end(),v[i]));
    }
}
int c=0;
for(auto it=s.begin(); it!=s.end();it++){
    printf("(%d,%d) ",*it,dif[c]);
    c++;
}       cout<<endl;
v.clear();  s.clear();  dif.clear();
}
return 0;
}
