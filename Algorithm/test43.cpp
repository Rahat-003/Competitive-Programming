#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>>mp;
bool check(){
    queue<int>q;
    map<int,bool>clr;
    int a;
    for(auto it=mp.begin(); it!=mp.end();++it){
        a=it->first;
        break;
    }
    q.push(a);
    clr[a]=false;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<mp[u].size();++i){
            int child = mp[u][i];
            if(!clr.count(child)){
                clr[child] = !clr[u];
                q.push(child);
            }
            else if(clr[child]==clr[u])
                return false;
        }
    }
return true;
}


int main(){

int n;
cin>>n;
int e;
cin>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
    mp[b].push_back(a);
}
cout<<check();




return 0;
}
