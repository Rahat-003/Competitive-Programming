#include <bits/stdc++.h>
using namespace  std;
int n;
vector<vector<int> > v;

bool func(){
int s =0;
vector<bool>clr(n,false);
queue<int>q;
clr[s] = true;
q.push(s);
    while(q.empty()==false){
        int u =q.front();
        q.pop();
        for(int i=0;i< v[u].size();++i){
            int child = v[u][i];
            if(!clr[child]){
               clr[child]=!clr[u];
                q.push(child);
            }
            else if(clr[child]==clr[u])
                return false;
    }
    }
return true;
}


int main(){
cin>>n;
int e;
cin>>e;
v.assign(n+1,vector<int>());
while(e--){
        int a,b;
cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
cout<<func()<<endl;



return 0;
}
