#include <bits/stdc++.h>
using namespace std;

int bal(string s){
int a[]={1,3,2,-1,-3,-2};
int r=0, st=0;
for(int i=s.size()-1;i>=0;i--){
    int d=s[i]-'0';
    r+=d*a[st];
    st=(st+1)%6;
    r%=7;
}
if(r<0)(r+7)%7;
return r;
}
int main(){
string s;
cin>>s;
cout<<bal(s);

return 0;
}
