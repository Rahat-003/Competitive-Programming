
#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<int>> v;
vector<int> dis,low,par;
vector<bool> vis;

void ap(int a){
    static int time = 0;

    dis[a] = low[a] = ++time;
    vis[a] = true;

    int children = 0;

    for(auto child:v[a]){
        children++;

        if(!vis[child]){

            par[child] = a;
            ap(child);
            low[a] = min(low[a],low[child]);

        if(children>1 && par[a]==-1){
            cout<<a<<" "<<child<<endl;
        }

        if(par[a]!=-1 && low[child]>dis[a] )
            cout<<a<<" "<<child<<endl;

        }

        else if(child!=par[a]){
            low[a] = min(dis[child],low[a]);
        }


    }




}


int main(){

cin>>n>>e;

v.assign(n,vector<int>());
vis.assign(n,false);
dis.assign(n,0);
par.assign(n,-1);
low = dis;

while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}

for(int i = 0 ; i<n; i++)
    if(!vis[i])
        ap(i);






}
