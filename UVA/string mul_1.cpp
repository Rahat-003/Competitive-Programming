#include <bits/stdc++.h>
using namespace std;

string mul(string a, string b){
    vector<int> result(a.size()+b.size(),0);
    if(a=="0" || b=="0")
        return "0";
    string s="";
    s.clear();
    int i1,i2,x,y;
    i1=0;
    for(int i=a.size()-1;i>=0;i--){
        int carry=0;
        i2=0;
         x= a[i]-'0';
        for(int j=b.size()-1;j>=0;j--){
             y= b[i]-'0';
            int ans= x*y + result[i1+i2]+carry;
            carry=ans%10;
            result[i1+i2]+=carry/10;
            i2++;
        }
        if(carry) result[i1+i2] +=carry;
        i1++;
    }
    reverse(result.begin(),result.end());
    for(auto i:result)
    	cout<<i;
    	cout<<endl;
}

int main(){
string a,b;
while(cin>>a>>b){
	mul(a,b);
//  cout<<  mul(a,b)<<endl;

}

return 0;
}
