#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

typedef pair<int,int> pp;

int n;
vector<pp> v;

bool check(int x,int i){
    return (x&(1<<i));
}

int Set(int x,int i){
    return x|(1<<i);
}

int L(int n){
    int x = log10(n);
    return x+1;
}

void fn(int pos,int mask,int x){
    if(pos==5){
        int y = x/n,tmp = y;
        if(x%n==0){
        while(y){
            mask = Set(mask,y%10);
            y/=10;
        }
        if(L(x)==5 && L(tmp)==4 && !check(mask,0))  mask = Set(mask,0);
        if(mask==(1<<10)-1)     v.push_back(pp(x,x/n));

        }

        return;
    }

    for(int i = 0; i<=9; i++){
        if(check(mask,i))   continue;
        fn(pos+1,Set(mask,i),x*10+i);
    }
}


main(){
int t,tc = 0;

while(1==scanf("%d",&n)){
    if(!n)  break;
    if(tc)
        puts("");

    fn(0,0,0);
    sort(v.begin(),v.end());
    if(!v.size())   printf("There are no solutions for %d.\n",n);
    else{

    for(pp i:v){
        int x = i.first,y = i.second;
        if(L(x)==4) printf("0");
        printf("%d / ",x);
        if(L(y)==4) printf("0");
        printf("%d = %d\n",y,n);
    }

    }
    v.clear();
    tc++;
}

return 0;
}
