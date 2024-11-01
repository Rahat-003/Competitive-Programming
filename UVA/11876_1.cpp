#include <iostream>
#include <cstdio>
using namespace std;
int fact(int m){
    int c=0;
    for(int i=1;i*i<=m;i++){
            if(m%i==0){
                c+=2;
            if(i*i==m) c-=1;
            }
        }
return c;
}
int ar[1000001];
int main(){
//freopen("11876.txt","r",stdin);
int t;
cin>>t;
int a;
int x=1;
while(x<=1000001){
    ar[x]=1;
    x += fact(x);
}
for(int i=1;i<=1000001;i++){
    ar[i]+=ar[i-1];
}
int cnt=0;
while(t--){
        int c,d;
    cin>>c>>d;
    cnt++;
    printf("Case %d: %d\n",cnt,ar[d]-ar[c-1]);
}

return 0;
}
