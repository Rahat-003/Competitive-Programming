#include <bits/stdc++.h>
using namespace std;
string ar[1005];
string m(string a, string b){
    if(a=="0"||b=="0")
        return "0";
        vector<int> v(a.size()+b.size(),0);
    int i1=0,i2,carry;
    for(int i=a.size()-1;i>=0;i--){
        carry=0;
        i2=0;
        for(int j=b.size()-1;j>=0;j--){
            int ans=(a[i]- '0')*(b[j]- '0')+v[i1+i2]+carry;
            carry=ans/10;
            v[i1+i2]=ans%10;
            i2++;
        }
        if(carry) v[i1+i2]+=carry;
        i1++;
    }
    int x=v.size()-1;
    while(1){
        if(v[x]!=0)
            break;
        x--;
    }
    string s;
    for(int i=x;i>=0;i--){
        s.push_back(v[i]+ '0');
    }
    return s;

}

void fact(){
    ar[0]="1";
    string ans="1";
    for(int i=1;i<=1001;i++){
        stringstream ss;
        ss<<i;
        string a=ss.str();
        ans=m(ans,a);
        ar[i]=ans;
    }
}


int main(){
string a,b;
int i;
fact();
while(cin>>i)
cout<<ar[i]<<endl;

return 0;
}
