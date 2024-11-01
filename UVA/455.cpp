#include <bits/stdc++.h>
using namespace std;
int main(){
  // freopen("455.txt","r",stdin);
int tc;
scanf("%d",&tc);
while(tc--){
    string s;
    //scanf("%s",&s);
    scanf("\n");
    cin>>s;
    vector<int>v;
    int x=s.size();
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            v.push_back(i);
            v.push_back(x/i);
        }
    }
    v.push_back(1);
    int y = v.size();int c=1;

    if(v.size()!=0){
            int i1,flg,j,k;
        sort(v.begin(),v.end());
        for(int i = 0;i<y;i++){
            i1=v[i],flg=0;
        for(j=0;j<i1;j++){
            for(k = j+i1;k<x;k+=i1){
                if(s[k]!=s[j])break;
                else flg++;
            }
        }
        if(flg+i1 == x){
          c=0;  cout<<i1<<endl; break;
        }
        }
    }
    if(c!=0) cout<<x<<endl;
    if(tc>0) cout<<endl;
v.clear();
}
return 0;
}
