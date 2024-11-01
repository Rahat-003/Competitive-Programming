#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
bool arr[MAX];


void sieve(){
memset(arr,true,sizeof(arr));
arr[0]=arr[1]=false;
for(int i=4;i<MAX;i+=2)
    arr[i]=false;
for(int i=3;i*i<MAX;i+=2){
    if(arr[i]){
        for(int j=i*i;j<MAX;j+=i){
            if(arr[j])
                arr[j]=false;
        }
    }

}
}


int main(){
    sieve();
    int a,b;
    cin>>a>>b;
    vector<int>prime;
    vector<int>prime1;
for(int i=a;i<=b;i++){
    if(arr[i])
        prime.push_back(i);

}
for(int i=1;i<prime.size();i++)
    prime1.push_back(prime[i]-prime[i-1]);

int cnt=count(prime1.begin(),prime1.end(),prime1[0]);
int champ=prime1[0];
for(int i=1;i<prime1.size();i++){
    if(count(prime1.begin(),prime1.end(),prime1[i])>=cnt){
        cnt=count(prime1.begin(),prime1.end(),prime1[i]);
        champ=prime1[i];
    }
}
cout<<cnt<<" "<<champ<<endl;
return 0;
}
