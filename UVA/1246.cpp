
#include <cstdio>
#include <vector>
using namespace std;
#define mx (int)1e4+3

bool mark[mx];
vector<int> prime;
bool ar[mx];

void sieve(){
    mark[0] = mark[1] = 1;

    for(int i = 4; i<mx; i+=2)
        mark[i] = 1;

    for(int i = 3; i*i<=mx; i+=2){
        if(!mark[i]){
            for(int j = i*i; j<mx; j+=2*i)
                mark[j] = 1;
        }
    }

    prime.push_back(2);

    for(int i = 3; i<mx; i+=2){
        if(!mark[i])
            prime.push_back(i);
    }
}

bool factor(int n){
    if(n<2) return false;
    if(!mark[n])    return true;


    int ans = 1;

    for(auto i:prime){
        if(i>n) break;

        if(n%i==0){
            int x = 1;
            while(n%i==0){
                x++;
                n/=i;
            }
            ans*=x;
        }
    }

    if(n>1) ans*=2;

    if(ans<mx)  return !mark[ans];

}

void func(){
    for(int i = 2; i<mx; i++)
        ar[i] = factor(i);
}

int main(){
sieve();
func();

int t;

scanf("%d",&t);


while(t--){
    int p,q;
    scanf("%d %d",&p,&q);

    bool fl = false;
    for(int i = p ; i<=q; i++){
        if(ar[i]){
        if(fl)    printf(" ");
            printf("%d",i);
            fl = 1;
        }
    }

    if(!fl) puts("-1");
    else    puts("");
}



return 0;
}
