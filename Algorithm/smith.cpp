#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;
ll sum(int a){
ll s=0;
if(a<10)
    s+=a;
else{
    while(a!=0){
        s+=a%10;
        a/=10;
    }
}
return s;
}
// (2^6)*3*5 * 941 (prime) = 903360
ll prime(int a){
    ll s=0;

while(a%2==0){
    v.push_back(2);
    s+=2;
    a/=2;
}

for(int i=3;i*i<=a;i+=2){
    while(a%i==0){
        v.push_back(i);
        s+=sum(i);
        a/=i;
    }
}
if(a>2){
    v.push_back(a);
    s+=sum(a);
}
return s;
}


int main(){
ll a;
while(cin>>a){

    for(ll i=a+1;;i++){
            v.clear();
        if(sum(i)==prime(i) && v.size()!=1){
            cout<<i<<endl;
            break;
        }
    }
}


return 0;
}
