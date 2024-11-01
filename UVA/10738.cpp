#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define lim 1005
#define mx 1000003

int mu[mx], M[mx];
bool ar[mx];

vector<int> prime;

void sieve(){
    prime.push_back(2);
    for(int i = 3; i*i<=lim; i+=2){
        if(!ar[i])
            for(int j = i*i; j<lim; j+=2*i)
                ar[j] = 1;
    }
    for(int i = 3; i<lim; i+=2)
        if(!ar[i])  prime.push_back(i);
}

int factor(int n){
    int tot = 0;
    for(auto i:prime){
        if(i>n) break;
        if(n%i==0){
                tot++;
            int cnt = 0;
            while(n%i==0){
                cnt++;
                if(cnt>1)   return 0;
                n/=i;
            }
        }
    }
    if(n>1) tot++;
    if(tot&1)   return -1;
    return 1;
}

void calc(){
    mu[1] = M[1] = 1;

    for(int i = 2; i<mx; i++){
        mu[i] = factor(i);
        M[i]+= M[i-1] + mu[i];
    }
}


int main(){
    sieve();
    calc();
int n;

while(1==scanf("%d",&n)){
    if(!n)  break;
    string x = to_string(mu[n]),y = to_string(M[n]), z = to_string(n);

    string spc1(8-z.size(),' '), spc2(8-x.size(),' '), spc3(8-y.size(),' ');

    printf("%s%s%s%s%s%s\n",spc1.c_str(),z.c_str(),spc2.c_str(),x.c_str(),spc3.c_str(),y.c_str());
}



return 0;
}
