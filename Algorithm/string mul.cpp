
#include <bits/stdc++.h>
using namespace std;

string mul(string a, string b){
if(a=="0"||b=="0")
    return "0";
    vector<int> v(a.size()+b.size(),0);
    int i1,i2,carry,ans;
    i1=0;
    for(int i=a.size()-1;i>=0;i--){
        i2=0;
        carry=0;
        for(int j=b.size()-1;j>=0;j--){
            ans=(a[i]- '0')*(b[j]- '0')+v[i1+i2]+carry;
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
    s.push_back(v[i]+ '0');
}
return s;

}
int main(){

string a,b;
while(cin>>a>>b){
    cout<<mul(a,b)<<endl;
}
return 0;
}
