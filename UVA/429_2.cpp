#include <bits/stdc++.h>
using namespace std;
    vector<string> v;
    vector<string> nv;
    vector<int>vis;

void func( int m , int n ){
int i1=n,i;
for( i=m;i<v.size();i++){
    string tmp=v[i];
    string cmp=nv[i1];
    int cnt=0;
    if(!vis[i]){
        for(int j=0;j<tmp.size();j++){
            if(tmp[j]!=cmp[j]) cnt++;
            if(cnt>1)break;
        }
    }
    if(cnt==1){
        nv.push_back(tmp);
        i1=nv.size()-1;
        vis[i]=1;
        break;
    }
}
int p;
for(p=1;p<vis.size();++p)
    if(!vis[p])
    break;

func(p,i1);
}


int main(){
int t;
cin>>t;
while(t--){
    string s,ss;
    cin>>s;
    v.push_back(s);
    nv.push_back(s);
    vis.push_back(1);
    while(cin>>ss){
        if(ss=="*") break;
        v.push_back(ss);
        vis.push_back(0);
    }
int x=1,y=0;
func(x,y);
for(int i=0;i<nv.size();i++)
    cout<<nv[i]<<endl;


}
return 0;
}

