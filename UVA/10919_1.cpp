#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
using namespace std;
int main(){
int t;
cin>>t;
int taka[10],b,p;
memset(taka,0,sizeof(taka));
string name[10];
string s,u,v;
for(int i=0;i<t;i++){
    cin>>s;
    name[i]=s;
}
for(int i=0;i<t;i++){
    cin>>u>>b>>p;
    for(int k=0;k<p;k++){
        cin>>v;
        for(int l=0;l<t;l++){
            if(name[l]==v){
             if(p!=0){taka[l]+=b/p;}
             else if(p==0) {
                    taka[l]+=0;}
            }
            if(name[l]==u){
                if(p!=0){
                taka[l]+=b%p-b;
                }
            else if(p==0){
                        taka[l]+=b;}
            }
            }
            }
}
for(int f=0;f<t;f++ ){
    cout<<name[f]<<" "<<taka[f]<<endl;
}


return 0;
}
