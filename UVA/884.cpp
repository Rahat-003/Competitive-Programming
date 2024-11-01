
#include <cstdio>
#include <vector>
using namespace std;


#define Mx (int)1e6+2

vector<int> prime;

bool ar[Mx];
int mark[Mx];

void sieve(){

    for(int i = 4; i<Mx; i+=2)
        ar[i] = true;

    ar[0] = ar[1] = true;
    prime.push_back(2);
    for(int i = 3; i*i<=Mx; i+=2){
        if(!ar[i]){
            prime.push_back(i);
            for(int j = i*i; j<Mx; j+=2*i)
                ar[j] = true;
        }
    }

}

int fac(int n){

    if(!ar[n]) return 1;

    int ans = 0;
    for(auto i:prime){
        if(i>n) break;

        while(n%i==0){
            ans++;
            n/=i;
        }
        if(!ar[n])  break;
    }
    if(n>1){
        ans++;
    }

    return ans;
}

void factor(){
    int ans = 0;
    for(int i = 2; i<=Mx; i++){
        ans+=fac(i);
        mark[i] = ans;
    }
    return;
}

int main(){

sieve();

factor();


int n;

while(1==scanf("%d",&n)){
    int ans = mark[n];
    printf("%d\n",ans);
}




return 0;
}
