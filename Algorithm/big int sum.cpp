#include <bits/stdc++.h>
using namespace std;
string sum(string a,string b){
if(a.size()>b.size()) swap(a,b);
int ans;
int carry=0;
reverse(a.begin(),a.end());
reverse(b.begin(),b.end());
string s;
s.clear();
for(int i=0;i<a.size();i++){
    ans=(a[i]-'0')+(b[i]-'0')+carry;
    carry=ans/10;
    s.push_back((ans%10)+'0');
}
for(int i=a.size();i<b.size();i++){
    ans=b[i]-'0'+carry;
    carry=ans/10;
    s.push_back((ans%10)+'0');
}
if(carry) s.push_back(carry+'0');
reverse(s.begin(),s.end());
return s;

}

int main(){

string a,b;
while(cin>>a>>b){
cout<<sum(a,b)<<endl;
}
return 0;
}
