#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//string m(string a, string b)
ll ar[15];
void fact(){

    for(int i=8; i<=13;i++){
    ll a=1;
    for(int j=2;j<=i;j++){
        a*=j;
    }
    ar[i] = a;
    }

}


int main(){
    //freopen("10323.txt","r",stdin);
ll n;
fact();
while(cin>>n){
    if(n<0){
        ll a=abs(n);
    if(a%2==0)
    cout<<"Underflow!"<<endl;
    else cout<<"Overflow!"<<endl;
    }
else{
    if(n<=7)
        cout<<"Underflow!"<<endl;
    else if(n>13)
        cout<<"Overflow!"<<endl;
    else if(n>7) cout<< ar[n]<<endl;
}
}

return 0;
}
