#include <bits/stdc++.h>
using namespace std;
vector<string>v;
vector<string>nv;
vector<bool>vis;

void func(int a,int b){
    int i1= b;
    for(int i=a;i<v.size();i++){
        string tmp,cmp;
        tmp =v[i];
        cmp =nv[i1];
        int cnt=0;
        if(!vis[i]){
        for(int j=0;j<tmp.size();j++){
            if(tmp[j]!=cmp[j]) cnt++;
            if(cnt>1) break;
        }
    }
    if(cnt==1){
        nv.push_back(tmp);
        i1=nv.size()-1;
        vis[i]=true;
    }

    }
}

int main(){
int t;
cin>>t;
while(t--){
    string ss,s;
    cin>>s;
    v.push_back(s);
    nv.push_back(s);
    vis.push_back(true);
    while(cin>>ss){
        if(ss=="*") break;
        v.push_back(ss);
        vis.push_back(false);
    }
    for(int i=1;i<v.size();i++){
    if(!vis[i])
        func(1,nv.size()-1);

 }

    for(int i=0;i<nv.size();i++)
        cout<<nv[i]<<endl;
}






return 0;
}
