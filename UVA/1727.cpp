#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
map<string,int> mp,np;

void B(){
    mp["JAN"] = mp["MAR"]=mp["MAY"]=mp["JUL"]=mp["AUG"]=mp["OCT"]=mp["DEC"] = 31;
    mp["FEB"] = 28;
    np["SUN"]=0;
    np["MON"]=1;
    np["TUE"]=2;
    np["WED"]=3;
    np["THU"]=4;
    np["FRI"]=5;
    np["SAT"]=6;
}

int main(){
int t,tc = 0;
B();
cin>>t;
while(t--){
    string m,d; cin>>m>>d;
    int ar[10];  for(int i = 0; i<10; i++)  ar[i] = 0;
    int M = (mp[m])?mp[m]:30;
    int D = np[d];
    for(int i = 0; i<M; i++)   ar[(D+i)%7]++;
    printf("%d\n",ar[5]+ar[6]);
}


return 0;
}

