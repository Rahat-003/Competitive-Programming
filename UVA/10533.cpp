
#include <iostream>
using namespace std;
#define mx (int)1e6+3
bool ar[mx];
int tot[mx];

//vector<int> prime;

bool check(int a){
//    if(a>2 && a%2==0)   return false;

    string s = to_string(a);
    if(s.size()==1) return true;
    int ans = 0;
    for(int i = 0;i<s.size(); i++){
        ans+= s[i] - '0';
    }
    if(ans==2)  return true;
    if( (ans&1) && !ar[ans] )   return true;
    return false;
}

void sieve(){
//    prime.push_back(2);
    ar[1] = true;
    for(int i = 3; i*i<=mx; i+=2){
        for(int j = i*i; j<mx; j+=2*i)
            ar[j] = true;
    }
}

void bal(){
    int cnt = 0;
    for(int i = 1; i<mx; i++){
        tot[i] = cnt;
        if(i==2)  tot[i] = ++cnt;
        if(i>2 && i&1 && !ar[i] && check(i))    tot[i] = ++cnt;
    }
}


int main(){
sieve();
bal();

int t;
scanf("%d",&t);
while(t--){
    int x,y;
    scanf("%d %d",&x,&y);
    int P = tot[y];
    int Q = tot[x-1];
    printf("%d\n",P-Q);
}


return 0;
}

