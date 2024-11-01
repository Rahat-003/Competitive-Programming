/*******
    Inverse Modulo  of
     a^-1%b = (x+b)%b   using extended eucild
    Inverse  modulo from [1,2,3..m-1]%m     in O(m)
*******/
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

int gcd(int a,int b,int &x,int &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    int g = gcd(b%a,a,x1,y1);
    y = x1;
    x = (g-b*y)/a;
    return g;
}

int inv[102];


int main(){
int t,tc = 0;

int a,m;
while(cin>>a>>m){
    int x,y;
    int g = gcd(a,m,x,y);
    x = (x+m)%m;
    cout<<x<<"\n";
    inv[1] = 1;
    for(int i = 2; i<m; i++)
        inv[i] = (m-(m/i*inv[m%i])%m)%m;
    for(int i = 1; i<m; i++)
        cout<<i<<" "<<inv[i]<<endl;
}

return 0;
}
