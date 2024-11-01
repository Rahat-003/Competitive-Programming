#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
using namespace std;
int main(){
int t;
cin>>t;

int taka[10],b,p,x;x=t;
memset(taka,0,sizeof(taka));
string name[10];
string s,u,v;
for(int i=0;i<t;i++){
    cin>>s;
    name[i]=s;
}
while(t--){
    cin>>u>>b>>p;
    for(int k=0;k<p;k++){
        cin>>v;
        for(int l=0;l<t;l++){

            if(name[l]==v){
                taka[l]+=b/p;
            }
            if(u==name[l]){
                taka[l]=b%p;
                taka[l]-=b;
            }
        }
    }


}
for(int f=0;f<t;f++ ){
    cout<<name[f]<<" "<<taka[f]<<endl;
}


return 0;
}
