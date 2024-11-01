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




main(){
int t,tc = 0;

double ans = 1,x = 0;
int i;

for(i = 1; x<50.0; i++ ){
    ans = ans*double((365.0-i)/365.0);
    x = (1-ans)*100.0;
}
cout<<i<<endl;

return 0;
}
