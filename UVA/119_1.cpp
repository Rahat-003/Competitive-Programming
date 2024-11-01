#include <iostream>
#include <cstring>
using namespace std;
int main(){
int t;
cin>>t;
int taka[10];
memset(taka,0,sizeof(taka));
string name[10],s,x;
for(int i=0;i<t;i++){
    cin>>s;
    name[i]=s;
}
for(int i=0;i<t;i++){
    int y,z;
    string x;
    cin>>x>>y>>z;
    for(int j=0;j<z;j++){
        string e;
        cin>>e;
        for(int k=0;k<t;k++){
            if(x==name[k]){
                if(z!=0){
                    taka[k]-=y-y%z;
                }
                if(z==0){
                    taka[k]+=y;
                }
            }
            if(e==name[k]){
              if(z!=0) { taka[k]+=y/z;}
              if(z==0){
                taka[k]+=0;
              }
            }
        }
    }

}
for(int g=0;g<t;g++){
    cout<<name[g]<<" "<<taka[g]<<endl;
}


return 0;

}
