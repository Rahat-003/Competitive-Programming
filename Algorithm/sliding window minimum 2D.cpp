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
#define mx 105
int ar[mx][mx],ara[mx][mx],ans[mx][mx];
typedef pair<int,int> pp;
deque<pp> dq;

void push(int x,int y){
    while(dq.size() && dq.back().first>x)  dq.pop_back();
    dq.push_back(pp(x,y));
}


main(){
int t,tc = 0;

int n,m,p,q;
cin>>n>>m;

for(int i = 1; i<=n; i++)
    for(int j = 1; j<=m; j++)   ar[i][j] = 1+rand()%9;

//    ar[3][3] = ar[3][5] = 10;
for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++)
        cout<<ar[i][j]<<" ";
    cout<<endl;
}

cout<<endl;

cin>>p>>q;

for(int i = 1; i<=n; i++){
    dq.clear();
    for(int j = 1, k = 0; j<=m; j++){
        int x = ar[i][j];
        push(x,j);
        if(j>=q){
            ara[i][++k] = dq.front().first;
//            if(i==4)    cout<<ara[i][k]<<" ";
            if(dq.front().second+q-1==j)    dq.pop_front();
        }
    }
}

//cout<<endl<<endl;

for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m-q+1; j++)   cout<<ara[i][j]<<" ";
    cout<<endl;
}

for(int i = 1; i<=m-q+1; i++){
    dq.clear();
    for(int j = 1,k = 0; j<=n; j++){
        int x = ara[j][i];
        push(x,j);
        if(j>=p){
            k++;
            ara[k][i] = dq.front().first;
//            ans[k][i] = dq.front().first;
            if(dq.front().second+p-1==j)   dq.pop_front();
        }
    }
}

cout<<endl;

for(int i = 1; i<=n-p+1; i++){
    for(int j = 1; j<=m-q+1; j++)
//        cout<<ara[i][j]<<" ";
        cout<<ara[i][j]<<" ";
    cout<<endl;
}

return 0;
}

