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


#define mx 1002



int ar[mx][mx];

/// Grid Must be 1-indexed

int Sum[mx][mx];

int query(int a,int b,int c,int d){
    /**
        (a,b) = top left corner
        (c,d) = bottom right corner
    */
    return Sum[c][d]+Sum[a-1][b-1]-Sum[a-1][d]-Sum[c][b-1];
}


main(){
int t,tc = 0;

int n,m;
cin>>n>>m;

for(int i = 1; i<=n; i++)
    for(int j = 1; j<=m; j++){
//            cin>>ar[i][j];
        int x;
        cin>>x;
///         Both assignment of Sum[i][j] is correct

//        Sum[i][j] = x - Sum[i-1][j-1] + Sum[i][j-1] + Sum[i-1][j];
        Sum[i][j] = x-query(i,j,i,j);

    }


cout<<endl;

//for(int i = 1; i<=n;i++){
//    for(int j = 1; j<=m; j++)   cout<<Sum[i][j]<<" ";
//    cout<<endl;
//}
//cout<<endl;

int a,b,c,d;
while(cin>>a>>b>>c>>d)  cout<<query(a,b,c,d)<<endl;

return 0;
}
