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


int ar[102];

main(){
int t,tc = 0;

int x = 0;
for(int i = 1; i<=10; i++){
    ar[x++] = i;
    ar[x++] = 10-i+1;
}
sort(ar,ar+x);
x = unique(ar,ar+x) - ar;

for(int i = 0;i<x; i++) cout<<ar[i]<<" ";
cout<<endl;

return 0;
}
