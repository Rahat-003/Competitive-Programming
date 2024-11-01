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
#define mx 100005
int ar[mx];
deque<int> dq;

/// 1 7 4 0 9 4 8 8 2 4

/**
*
*   For minimum in push function dq.back()>x
*   For maximum in push function dq.back()<x
*
**/

void push(int x){
    while(dq.size() && dq.back()>x) dq.pop_back();
    dq.push_back(x);
}

main(){
int t,tc = 0;

int n,k;
cin>>n>>k;

for(int i = 0; i<n; i++)
    ar[i] = rand()%10;

for(int i = 0; i<n; i++)   cout<<ar[i]<<" ";   cout<<endl;
cout<<endl;


for(int i = 0; i<n; i++){
    int x = ar[i];
    push(x);
    if(i>=k-1){
        int y = dq.front(),id = i-k+1;
        cout<<y<<" ";
        if(id<=n && ar[id]==y)    dq.pop_front();
    }
}
cout<<endl;

return 0;
}

