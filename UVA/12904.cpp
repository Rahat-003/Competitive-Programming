#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 10001
#define EPS 1e-10

double ar[mx];
int ara[162];

main(){
//    read;
int t,tc = 0;
scanf("%d",&t);

while(t--){
    int n;
    scanf("%d",&n);
    double p = ((double)n)/4.0;
    memset(ara,0,sizeof ara);

    for(int i = 0; i<n; i++){
        int x;
        scanf("%d",&x);
//        ar[i] = x;
        ara[x]++;
    }
//    sort(ar,ar+n);

    double MX = 10000000000.0;
    int a = 0,b = 0,c = 0;
    int g1,g2,g3;

    for(int i = 0; i<=157; i++){
        a += ara[i];    b=0;  c=0;
        for(int j = i+1; j<=158; j++){
            b+=ara[j];  c=0;
            for(int k = j+1; k<=159; k++){
                c+=ara[k];
                double x = a,y = b,z = c,w = n-a-b-c;
                if( fabs(x-p) + fabs(y-p) + fabs(z-p) + fabs(w-p)<MX ){
                    MX = fabs(x-p) + fabs(y-p) + fabs(z-p) + fabs(w-p);
//                    a = x,b = y,c = z;
                    g1 = i,g2 = j,g3 = k;
                }
            }
        }
    }
    case;
//    cout<<MX<<endl;
    printf("%d %d %d\n",g1,g2,g3);
}



return 0;
}
