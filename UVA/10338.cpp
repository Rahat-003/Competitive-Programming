
#include <cstdio>
#include <cstring>
#include <unordered_map>
typedef unsigned long long ull;
using namespace std;

int main(){
int t,tc = 0;
scanf("%d",&t);

while(t--){
    unordered_map<char,ull> mp;
    char ar[25];
     scanf("%s",ar);
     ull ans = 1;
     for(ull i = 1; i<=strlen(ar); i++){
        mp[ar[i-1]]++;
        ans*=i;
     }

     for(auto i:mp){
        if(i.second>1){
            for(ull j = 2; j<=i.second; j++)    ans/=j;
        }
     }
     printf("Data set %d: %llu\n",++tc,ans);
}




return 0;
}
