#include <bits/stdc++.h>
using namespace std;
vector<vector <int> > v(1000);
vector <bool> vis(1000,false);
int m;
void bfs(int a){
    vector <int> lvl(1000,1);
    lvl[a] = 1;
    vis[a] = true;
    queue <int> q;
    q.push(a);
    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int i = 0; i<v[u].size();i++){
            int child = v[u][i];
            if(vis[child]==false){
            vis[child] = true;
            lvl[child] = lvl[u] + 1;
            q.push(child);

            }
        }
    }
    cout<<endl;
    //cout<<"Hello ";
    for(int i = 1; i<=m+1; i++){
        cout<< i <<" "<< lvl[i]<<endl;
    }

}

int main(){

cin>>m;
        v.clear();
        vis.clear();
//        lvl.clear();
    int b,c;
    for(int i=0;i<m;i++){
        cin>>b>>c;
        v[c].push_back(b);
        v[b].push_back(c);
    }
    bfs(1);



return 0;
}
