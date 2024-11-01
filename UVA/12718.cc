#include <iostream>
#include <cstdio>
#include <memory.h>

#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
using namespace std;

#define mx 1002
int ar[26][mx];

bool fn(int l,int r){
    if(l==r)    return 1;

    int x = 0;

    for(int i = 0; i<26; i++){
        int p = ar[i][r] - (l==0?0:ar[i][l-1]);
        if(p&1) x++;
        if((r-l+1)%2==0){
            if(x){
                return 0;
            }
        }
        else{
            if(x>1){
                return 0;
            }
        }
    }
    if((r-l+1)&1 && x!=1)   return 0;
    return 1;
}


main(){
//read;
//write;
int t,tc = 0;
scanf("%d",&t);
while(t--){
    memset(ar,0,sizeof ar);
    string s;
    cin>>s;
    for(int i = 0; i<s.size(); i++)
        ar[s[i]-'a'][i]++;
    for(int i = 0; i<26; i++){
        for(int j = 1; j<s.size(); j++)
            ar[i][j]+=ar[i][j-1];
    }
    int ans = 0;
    int p = 0;
    for(int i = 0; i<s.size(); i++){
        for(int j = 0; j<=i; j++){
            bool fl = fn(j,i);
            if(fl)  ans++;
            p++;
        }
    }
    case;
    printf("%d\n",ans);
}


return 0;
}
