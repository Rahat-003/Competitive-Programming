#include <bits/stdc++.h>
using namespace std;
int main(){
 //   freopen("12068.txt","r",stdin);
long long t;
cin>>t;
long long tc=1;
while(t--){
    long long a;
    cin>>a;
    vector<long long>ar;
    long long ans=1;
    for(long long i=0;i<a;i++){
        long long b;
        cin>>b;
        ans*=b;
        ar.push_back(b);
    }
    long long sum=0;
    for(long long i=0;i<a;i++){
        sum+=ans/ar[i];
    }
    long long p=ans*a;
    long long q=sum;
    long long r=__gcd(p,q);
    printf("Case %lld: %lld/%lld\n",tc++,p/r,q/r);


}

return 0;
}
