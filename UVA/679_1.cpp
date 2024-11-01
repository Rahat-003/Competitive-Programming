#include <iostream>
using namespace std;

void bal(int ar[],int i){
    ar

}

int main(){
int n;
cin>>n;
int p=1,m=1;
int l;
for(int i=2;i<=n;i++){
    p*=2;
    m+=p;
}
l=m-p+1;
cout<<l<<" "<<m<<" "<<p<<endl;

int ar[1000];
ar[0]=0;
int ll=l+1;
for(int i=l/2+1;i<=l;i++){
    ar[i]=ll;
    ll+=2;
}
cout<<ar[4];
int c=l/2,k=l;
int evn[1000]; evn[0]=0;
for(int i=1;i<=c;i++){
    evn[i]=k;
    k+=2;
}
ar[1]=l;int ss=l;
bal()


return 0;
}
