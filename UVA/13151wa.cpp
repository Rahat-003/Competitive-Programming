#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define pi acos(-1)
string s = "0123456789ABCDEF";
map<char,int> mp;

int TO_DEC(string s,int n){
    if(s=="0")  return 0;
    if(s[0]=='0'){
        if(s[1]=='x')   s = s.substr(2);
        else s = s.substr(1);
    }

    int ans = 0;
    int p = 1;
    vector<int> v(s.size(),1);
    for(int i = 1;i<v.size(); i++){
        p*=n;
        v[i]=p;
    }
    int sz = s.size()-1;
    for(int i = 0; i<s.size(); i++){
        int a = mp[s[i]];
        ans+=a*v[sz-i];
    }
    return ans;
}

void f(int p,string s,int &a,int &b){
    if(s=="i")  a = p, b = p;
    if(s=="++i")   a = p+1, b = p+1;
    if(s=="i++")   a = p, b = p+1;
    if(s=="--i")   a = p-1, b = p-1;
    if(s=="i--")   a = p,   b = p-1;
}
int  bal(string s,int n){
    if(s=="++i")    return n-1;
    if(s=="--i")    return n+1;
        return n;
}

int mm(string s,int n){
   if(s=="i++") return n+1;
   if(s=="i--") return n-1;
   return n;
}

int main(){
//    read;
int t,tc = 0;
for(int i = 0; i<s.size(); i++)
    mp[s[i]] = i;
string s;   int e;
//cout<<TO_DEC("0xAABC",16)<<endl;

while(cin>>s>>e){
    if(s=="0" && !e)    break;
    int P;
    if(s[0]=='0'){
        if(s[1]=='x')   P = TO_DEC(s,16);
        else P = TO_DEC(s,8);
    }
    else P = atoi(s.c_str());
    vector<string> A;   vector<int> B;
    while(e--){
        string a;   int b;  cin>>a>>b;
        A.push_back(a); B.push_back(b);
    }
    int cnt = 0;
    int a,b = B[0],p,d;
    if(bal(A[0],b)==P) cnt = 1;
    b = mm(A[0],b);
    for(int i = 1; i<B.size(); i++){
         string c = A[i];
        f(b,c,a,d);
        if(a==B[i]){
//            cout<<"de "<<c<<" "<<a<<" "<<b<<endl;
            cnt++;
        b = d;
        }
        else  b = B[i];

    }
    cout<<cnt<<endl;
}




return 0;
}
