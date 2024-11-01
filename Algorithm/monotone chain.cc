/***********
*   MONOTONE CHAIN : CONVEX HULL
*
***********/

#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 10003

struct point{
    int x,y;
    bool operator < (const point &n)    const{
        return (x<n.x || (x==n.x && y<n.y));
    }
};
point ar[mx];
vector<point> v;

int cross_product(point a,point b,point c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

void monotone_chain(int n){
    int k = 0;
    v = vector<point> (2*n);
    sort(ar,ar+n);
    for(int i = 0; i<n; i++){
        while(k>=2 && cross_product(v[k-2],v[k-1],ar[i])<=0)    k--;
        v[k++] = ar[i];
    }
    for(int i = n-1,j = k+1; i ; i--){
        while(k>=j && cross_product(v[k-2],v[k-1],ar[i-1])<=0)  k--;
        v[k++] = ar[i-1];
    }
    v.resize(k);
}

main(){
//read;
int n;
cin>>n;

for(int i = 0; i<n; i++)
    cin>>ar[i].x>>ar[i].y;

monotone_chain(n);
cout<<endl;
for(point i: v)
    cout<<i.x<<" "<<i.y<<endl;


return 0;
}

