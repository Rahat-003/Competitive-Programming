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


int fn(int d,int m,int y){
    if(m==2 && d==29)  return y/4-y/100+y/400;
    else return y;
}

int main(){
int t,tc = 0;
scanf("%d",&t);
while(t--){
    int d,m,y1,y2;
    scanf("%d%d%d%d",&d,&m,&y1,&y2);
    int ans = fn(d,m,y2) - fn(d,m,y1);
    case;
    printf("%d\n",ans);
}



return 0;
}
