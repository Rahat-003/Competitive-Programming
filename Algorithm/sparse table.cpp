
// mem: nlogn, query = O(1), initialize = nlogn
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
#define mx 20
int ar[] = {2, 3 ,0 ,6 ,4 ,1 ,2 ,5 ,5 ,9};
//int ar[] = {4,6,1,5,7,3};
//int ar[] = {3,2,5,1,4,6};
int sz;
int table[mx][mx];

void build(){

    int n = floor(log2(sz))+1;
    cout<<n<<endl;
    /*
    for(int i = 0; i<sz; i++){
        table[i][0] = ar[i];
    }*/
    for(int i = 0; i<=log2(sz); i++){
        for(int j = 0; j<sz; j++ ){
           if(!i){
            table[j][i] = j;
            continue;
           }
//           if(i1==-1 || i2==-1) break;
           if(j+(1<<(i-1))>=sz) break;
           int i1 = table[j][i-1],i2 = table[j+(1<<(i-1))][i-1];
           table[j][i] = (ar[i1]<= ar[i2] ? i1:i2);
        }
    }
}

int query(int l,int r){
    int len = r-l+1,k = log2(len);
    return min( ar[table[l][k]],ar[table[r+1-(1<<k)][k]] );
}


int main(){
int t,tc = 0;
sz = sizeof ar/4;
memset(table,-1,sizeof table);
build();
for(int i = 0; i<sz; i++){
    for(int j = 0; j<floor(log2(sz))+1; j++)    cout<<table[i][j]<<" ";
    cout<<endl;
}
cout<<endl;
/*
*/
int a,b;
while(cin>>a>>b)    cout<<query(a,b)<<endl;


return 0;
}
