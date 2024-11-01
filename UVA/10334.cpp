#include <bits/stdc++.h>
using namespace std;
    string ss;
string sum(string a, string b){
    if(a.size()>b.size())swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry=0;

    for (int i=0;i<a.size();i++){
        int ans = (a[i]-'0') + (b[i]-'0')+carry;
        carry=ans/10;
        ss.push_back(ans%10+'0');
    }
    for (int i=a.size();i<b.size();i++){
        int ans = (b[i]-'0')+carry;
        carry=ans/10;
        ss.push_back(ans%10+'0');
    }
    if(carry) ss.push_back(carry/10);
    reverse(ss.begin(),ss.end());
    return ss;
}
string ar[1001];
void fib(){
    ar[0]="1";
    ar[1]="2";
    string a="1", b="2",c;
    for(int i=2;i<1001;i++){
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
