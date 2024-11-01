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

#define mx 100003
int tree[mx+5];
/*
void add(int i,int val){
    for(;i<mx;i+=i&-i)  tree[i]+=val;
}

void range_add(int l, int r, int val) {
    add(l,val);
    add(r+1,-val);
}

int point_query(int i) {
    int sum = 0;
    for (; i>0; i-=i&-i )
        sum+= tree[i];
    return sum;
}

*/
int main(){
int t,tc = 0;

int fl,a,b,val;
/*
while(cin>>fl){
    if(fl==0){
        cin>>a>>b>>val;
        range_add(a,b,val);
        continue;
    }
    cin>>a;
    cout<<point_query(a)<<endl;
}
*/

return 0;
}

