#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen ("10407.txt","r",stdin);
int a;
while(1){
string s;
getline(cin,s);
if(s=="0") break;
istringstream ss(s);    vector<int> v;
while(ss>>a){
    if(a!=0)
        v.push_back(a);
}
int x=0;
if(v.size()==1) x=v[0];
for(int i=1;i<v.size();i++){
    int dif= abs(v[i-1]-v[i]);
    x=__gcd(x,dif);

}
cout<<x<<endl;
v.clear();
}
return 0;
}
