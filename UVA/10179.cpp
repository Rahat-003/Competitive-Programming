
#include <cstdio>
#include <vector>
using namespace std;

#define mx 32000
vector<int> prime;
bool ar[mx];

void sieve(){
    prime.push_back(2);
    for(int i = 3; i<=mx; i+=2){
        if(!ar[i]){
            prime.push_back(i);
            for(int j = i*i; j<mx; j+=2*i)
                ar[j] = true;
        }
    }
}


int phi(int n){
    if(n==1)    return 1;
    int ans = n;
    for(auto i:prime){
        if(i>n) break;
        if(n%i==0){
            while(n%i==0)   n/=i;
            ans-=ans/i;
        }
    }
    if(n>1) ans-=ans/n;
    return ans;
}


int main(){


sieve();

int n;
while(1==scanf("%d",&n)){
    if(!n)  break;
    int ans = phi(n);
    printf("%d\n",ans);

}


return 0;
}
