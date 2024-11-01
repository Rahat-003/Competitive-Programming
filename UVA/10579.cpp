#include <bits/stdc++.h>
using namespace std;
string ar[5001];
string sum(string a, string b){
    if(a.size()>b.size())
        swap(a,b);
        string ss;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry=0;
    for(int i=0;i<a.size();++i){
        int ans= (a[i]-'0')+(b[i]-'0')+ carry;
        carry=ans/10;
        ss.push_back(ans%10+'0');
    }
    for(int i=a.size();i<b.size();++i){
        int ans= (b[i]-'0')+ carry;
        carry=ans/10;
        ss.push_back(ans%10+'0');
    }
    if(carry) ss.push_back(carry+'0');
    reverse(ss.begin(),ss.end());
    return ss;
}

void fib(){
    ar[0]="0";
    ar[1]="1";
    string a="0",b="1",c;
    for(int i=2;i<4791;i++){
        c=sum(a,b);
        a=b;
        b=c;
        ar[i]=b;
    }

}
int main(){
fib();
int a;
while(cin>>a){
    cout<<ar[a]<<endl;
}

return 0;
}
