#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
bool a[MAX];
void seive(){
memset(a,true,sizeof(a));
a[0]=a[1]=false;
for(int i=2;i*i<=MAX;i++){
    if(a[i]){
        for(int j=i*2;j<=MAX;j+=i){
            a[j]=false;
        }
    }
}
}
void gold(int n){
    seive();
for(int i=n/2;i>=1;i--){
    if(a[i]&&a[n-i]){
        cout<<i<<" "<<n-i<<endl;
        break;
    }
    if(a[i]==1){
        cout<<"Error";
        break;
    }
}
}
//using namespace std;
int main(){
    int n;
    cin>>n;
    gold(n);

return 0;
}
