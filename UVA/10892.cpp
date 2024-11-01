#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;



int main(){
  // freopen("10892.txt","r",stdin);
ull n,p;
while(cin>>n){
        if(n==0) break;
    ull mul;
    int c = 0;
    p=n;
    vector <ull> factor;
    for(int i=1;i*i<=n;i++){
        if(n%i==0 && i*i!=n){
            factor.push_back(n/i);
            factor.push_back(i);
        }
        if(i*i==n)
            factor.push_back(i);
    }
    for(int i= 0;i<factor.size();i++){
        for(int j=i;j<factor.size();j++){
            if((factor[i]*factor[j])/__gcd(factor[i],factor[j]) == n)
                c++;
        }
    }
    cout<<n<<" "<<c<<endl;
    factor.clear();
}
return 0;
}
