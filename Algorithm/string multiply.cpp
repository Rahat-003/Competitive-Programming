#include<bits/stdc++.h>
using namespace std;
typedef long ll;

string multiply(string P, string Q){
    int x=P.size(),y=Q.size(),a=0,b,z,p,q,sum;vector<int>ans(x+y+2,0);if(x==0||y==0) return "0";string s;for(int i=x-1
    ;i>=0;i--){z=0,p=P[i]-'0',b=0;for(int j=y-1;j>=0;j--)q=Q[j]-'0',sum=p*q+ans[a+b]+z,z=sum/10,ans[a+b]=sum%10,b++;
    if(z>0)ans[a+b]+=z;a++;} for(int i=ans.size()-1;i>=0;i--)if(s.size()||ans[i])s.push_back(ans[i]+'0');return s;
}

string TO(ll n){
    if(n<=0)return "0";string s;while(n)s.push_back(n%10+'0'),n/=10;reverse(s.begin(),s.end());return s;
}
/// same as above
/*
string multiply(string num1, string num2){
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> result(n1+n2+2,0);
    if (n1 == 0 || n2 == 0)
    return "0";
    int i_n1 = 0;
    int i_n2;
    for (int i= n1-1; i>=0; i--){
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=n2-1; j>=0; j--){
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }
        if (carry > 0)
        result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0){
       i--;
    }
    string s = "";
    while (i >= 0){
        s.push_back(result[i]+'0');
        i--;
    }
    return s;
}
*/

int main(){
string a,b;
cin>>a>>b;
cout<<multiply(a,b);

return 0;
}
