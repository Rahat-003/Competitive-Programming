#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;



#define mx 60
int pref[2][mx],suff[2][mx],ar[mx];
int must[mx];


main(){
read;
int t,tc = 0;
scanf("%d",&t);
while(t--){

    string p,s = " ";
    cin>>p;
    s+=p;
    int n = s.size();
    memset(pref,0,sizeof pref);
    memset(suff,0,sizeof suff);
    memset(ar,0,sizeof ar);
    memset(must,-1,sizeof must);

    for(int i = 1; i<n; i++){
        if(s[i]=='?'){
            ar[i] = -1;
            continue;
        }
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')   ar[i] = 1;
        must[i] = ar[i];
    }

    ar[0] = ar[n] = -2;

    int cnt = 1;

    for(int i = 1; i<n; i++){
        if(ar[i]==-1)   continue;
        if(ar[i]==ar[i-1])  cnt++;
        else cnt = 1;
        pref[ar[i]][i] = cnt;
    }
    cnt = 1 ;
    for(int i = n-1; i; i--){
        if(ar[i]==-1)   continue;
        if(ar[i]==ar[i+1])  cnt++;
        else cnt = 1;
        suff[ar[i]][i] = cnt;
    }

    int fl = -1;
    for(int i = 1; i<n; i++){
        if(pref[0][i]>=5)   fl = 0;
        if(pref[1][i]>=3)   fl = 0;
        if(fl==0)   break;
        if(ar[i]!=-1)   continue;
        if(pref[0][i-1]==4 && suff[1][i+1]==2)  fl = 0;
        if(pref[1][i-1]==2 && suff[0][i+1]==4)  fl = 0;
    }

    for(int i = 1; i<n; i++){
        if(must[i+1]==-1 || must[i-1]==-1 || must[i]!=-1)  continue;
        if(i>1 && must[i-1]==1 && must[i-2]==1)    must[i] = 0;
        int w = 0;
        if(i>4){
            for(int j = i-3; j<i; j++)
                if(must[j]==must[j-1] && must[j]==0)    w++;
        }
        if(w==3)    must[i] = 1;
    }
    int a = 1,b = 1;
    for(int i = 1; i<n; i++){
        if(must[i]==must[i-1]){
            if(must[i]==1)  b++;
            if(must[i]==0)  a++;
        }
        else a = 1,b = 1;
        if(b==3 || a==5)    fl = 0;
    }

    case;
    if(fl==0){
        puts("BAD");
        continue;
    }
    cnt = 1;
    for(int i = 1; i<n; i++){
        if(ar[i]==ar[i-1] && ar[i]==-1)  cnt++;
        else cnt = 1;
        if(cnt==3)  fl = 0;
        if(fl==0)   break;
    }

    for(int i = 1; i<n; i++){
        int x = 0;
        for(int j = i,k = 0; k<3 && j<n; j++,k++){
            if(ar[j]!=0)    x++;
        }
        if(x==3)    fl = 0;
        x  = 0;
        for(int j = i,k = 0; k<5 && j<n; j++,k++){
            if(ar[j]!=1)    x++;
        }
        if(x==5)    fl = 0;

        if(fl==0)       break;
        if(ar[i]!=-1)   continue;
        if(ar[i-1]!=-1 && ar[i+1]!=-1){
            if(pref[1][i-1]+suff[1][i+1]>=2)    fl = 0;
            if(pref[0][i-1]+suff[0][i+1]>=4)    fl = 0;
        }
        if(ar[i+1]==-1){
            if(pref[1][i-1]+suff[1][i+2]>=1)    fl = 0;
            if(pref[0][i-1]+suff[0][i+2]>=3)    fl = 0;
        }

    }

    if(fl==0){
        puts("MIXED");
    }
    else puts("GOOD");

}


return 0;
}
