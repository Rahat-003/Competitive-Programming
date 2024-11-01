#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("10226.txt","r",stdin);
int t;
scanf("%d\n\n",&t);
while(t--){
    map<string,double>mp;
    char ar[35];
    double total=0;
    while(gets(ar)){
        if(strlen(ar)==0)   break;
        if(mp.count(ar)==0)
            mp[ar]=1;
        else mp[ar]+=1; total++;
    }
    for(auto it=mp.begin();it!=mp.end();++it)
cout<<it->first<<" "<<fixed<<setprecision(4)<<(it->second)/total*100<<endl;
if(t>0) cout<<endl;
}


return 0;
}
