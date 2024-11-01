#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define MAX 1000005

char P[MAX],T[MAX];
int b[MAX],t[MAX];

void kmpPreprocess() {
    int m = strlen(P);
int i = 0, j = -1; b[0] = -1;

while (i < m)
    {
while (j >= 0 && P[i] != P[j]) j = b[j];
i++; j++;
b[i] = j;
}
}

int kmpSearch() {
    int i = 0, j = 0,k=0;
int n=strlen(T);
int m=strlen(P);
while (i < n) {
while (j >= 0 && T[i] != P[j]) j = b[j];
i++; j++;
}
return j;
}


main(){
//read;

int ts;
scanf("%d",&ts);
for(int cs=1;cs<=ts;cs++)
{
    memset(b,0,sizeof(b));
    scanf("%s",&P);
    strcpy(T,P);
    int n= strlen(T);
    reverse(T,T+n);
    kmpPreprocess();
    int k=kmpSearch();
    cerr<<k<<endl;
    int ans;
//    if(k==n)ans=k;
//    else
        ans=n+(n-k);
    printf("Case %d: %d\n",cs,ans);
}



return 0;
}


