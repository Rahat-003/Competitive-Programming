#include <bits/stdc++.h>
using namespace std;
#define MAX 32003
vector <bool> v(MAX,true);
void sieve(){
    v[0]=false;
    v[1]=false;
    for(int i=4;i<MAX;i+=2)
        v[i]= false;
    for(int i=3;i*i<MAX;i++){
        if(v[i]){
            for(int j=2*i;j<MAX;j+=i)
                v[j] = false;
        }
    }
}


int main(){
    freopen("tst.txt","r",stdin);
int a,b;
sieve();
vector<int> prime;
for(int i=0;i<MAX;i++){
    if(v[i])
        prime.push_back(i);
   //9 else prime.push_back(0);
}
    vector<int> dif;
    dif.push_back(0);
for(int i =1 ;i<prime.size();i++){
    dif.push_back(prime[i]-prime[i-1]);
}
    vector <int> detr;

for(int i=1;i<dif.size();i++){
    if(dif[i]==dif[i-1]){
        if(dif[i-1] != dif[i-2]){
            detr.push_back(prime[i-2]);
            detr.push_back(prime[i-1]);
        }
        detr.push_back(prime[i]);
    }
}
/*

for(int i=0;i<detr.size();i++)
    cout<<detr[i]<<" ";
*/
while(cin>>a>>b){


int c=0,d;
for(int i=1;i<detr.size();i++){
    d=3;
        if( (detr[i]-detr[i-1]) == (detr[i+1] - detr[i]) ){
            if(detr[i+1]<=b && detr[i-1]>=a){
            if(c!=detr[i-1]){
            printf("%d %d %d\n",detr[i-1],detr[i],detr[i+1]);
            c = detr[i];
            }
            else {
                d++;
                printf("%d ",detr[i+1]);
                c= detr[i];
                if(d==4) cout<<endl;
            }


//cout<<endl;
            }

    }
}
}
return 0;
}
