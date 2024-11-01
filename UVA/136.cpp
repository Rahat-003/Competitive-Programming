
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> ugly;
ll f(){
    ll start = 0, cnt = 0;
    while(cnt<1500){
        start++;
        ll n = start;
        while(n%2==0) n/=2;
        while(n%3==0)  n/=3;
        while(n%5==0)   n/=5;
        if(n==1){
//        printf("%lld %lld\n",cnt,start);
            cnt++;
            ugly.push_back(start);
        }
    }
}

int main(){

//f();
//printf("The 1500'th ugly number is <%lld>.",ugly[1499]);
printf("The 1500'th ugly number is 859963392.\n");

return 0;
}
