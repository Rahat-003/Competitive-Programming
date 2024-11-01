
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define mx (int)1e3+3

int ar[mx];
bool arr[mx];
vector<int> prime;

void sieve(){
    memset(ar,-1,sizeof ar);

    ar[1] = 1;

    arr[1] = arr[0] = true;
    for(int i = 4; i<mx; i+=2)
        arr[i] = true;

  prime.push_back(2);

    for(int i = 3; i*i<=mx; i+=2){
        if(!arr[i]){
            for(int j = i*i; j<mx; j+=2*i)
                arr[j] = true;
        }
    }

    for(int i = 3; i<mx; i+=2){
        if(!arr[i]){
            ar[i+1] = i;
        prime.push_back(i);
        }
    }
}

int sumOfFactor(int n){
    int ans = 1;
    int N = n;

    for(auto i:prime){
        if(i>n) break;
        if(n%i==0){
            int x = i;

            while(n%i==0){
                x*=i;
                n/=i;
            }
            x-=1;
            x/=(i-1);
            ans*=x;
        }
    }
    if(n>1) {
        ans*= ((n*n)-1)/(n-1);
    }
    return ans;
}



void func(){

    for(int i = 2; i<=1000; i++){

        int sum = sumOfFactor(i);

        if(sum>=mx) continue;

        ar[sum] = max(ar[sum],i);
    }

}

int main(){

sieve();

func();


int n, tc=0;

while(1==scanf("%d",&n)){
        if(!n)  break;
    printf("Case %d: %d\n",++tc,ar[n]);

}




return 0;
}
