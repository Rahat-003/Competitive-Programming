#include <bits/stdc++.h>
using namespace std;

string m(string a, string b){
if(a=="0"||b=="0")
    return "0";
    vector<int> v(a.size()+b.size(),0);
    int i1,i2,carry,ans;
    i1=0;
    for(int i=a.size()-1;i>=0;i--){
        i2=0;
        carry=0;
        for(int j=b.size()-1;j>=0;j--){
            ans=(a[i]-'0')*(b[j]-'0')+v[i1+i2]+carry;
            carry=ans/10;
            v[i1+i2]=ans%10;
            i2++;
        }
        if(carry) v[i1+i2]+= carry;
        i1++;
    }
string s;
int x=v.size();
while(1){
    x--;
    if(v[x]!=0){
    break;
    }
}

for(int i=x;i>=0;i--){
    s.push_back(v[i]+'0');
}
return s;
}

string s(string a,string b){
    if(a.size()>b.size())
        swap(a,b);
    string ss;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry=0;
    for(int i=0;i<a.size();i++){
        int ans= a[i]-'0' + b[i]-'0' +carry;
        carry=(ans/10);
        ss.push_back(ans%10+'0');
    }
    for(int i=a.size();i<b.size();i++){
        int ans= b[i]-'0' +carry;
        carry=(ans/10);
        ss.push_back(ans%10+'0');
    }
    if(carry) ss.push_back(carry+'0');
    reverse(ss.begin(),ss.end());
    return ss;
}
//string ar[10000];

string factorial(string a){
    if(a=="0") return "1";

    string i="1",x="1",mul="1",sum="1";

    while(i!=a){
    string sum=s(i,"1");
    i=sum;
    mul = m(i,mul);
    mul= m(i,x);
    x=mul;
   }
   return mul;
}


int main(){

string a,b;
while(cin>>a){
    cout<<factorial(a)<<endl;

}
return 0;
}
