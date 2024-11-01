#include <bits/stdc++.h>
using namespace std;

string sum(string a, string b){
    if(a.size()>b.size())swap(a,b);reverse(a.begin(),a.end());reverse(b.begin(),b.end()); int c=0,ans,i;string s;for(
    i=0;i<a.size();i++) ans=(a[i]-'0')+(b[i]-'0')+c,c=ans/10,s.push_back((ans%10)+'0');for(i=a.size();i<b.size();i++)
    ans=(b[i]-'0')+c,c=ans/10,s.push_back((ans%10)+'0');if(c)s.push_back(c+'0');reverse(s.begin(),s.end());return s;
}

/*
string sum(string a, string b){
	if(a=="0")	return b;
	if(b=="0")	return a;
    if(a.size()>b.size())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int c=0,ans;
    string ss;
    ss.clear();
    for(int i=0;i<a.size();i++){
        ans=(a[i]-'0')+(b[i]-'0')+c;
        c=ans/10;
        ss.push_back((ans%10)+'0');
    }
    for(int i=a.size();i<b.size();++i){
         ans=(b[i]-'0')+c;
        c=ans/10;
        ss.push_back((ans%10)+'0');
    }
    if(c) ss.push_back(c+'0');
    reverse(ss.begin(),ss.end());
    return ss;
}
//*/

int main(){
string a,b;
cin>>a>>b;
cout<<sum(a,b);

return 0;
}
