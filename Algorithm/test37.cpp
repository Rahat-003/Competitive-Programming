#include <bits/stdc++.h>

using namespace std;
int a;
vector <bool>vis(1000,false);
vector < vector<int> > v(1000);
void bfs(int a){
    vis[a] = true;
    queue<int> q;
    q.push(a);
    vector<int> lvl(1000,1);
    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0;i<v[u].size();i++){
                int child = v[u][i];
            if(vis[child]==false{
                bfs(child);
                level[child] = level[u]+1;


            }
        }
        }
    }

}
int main(){

while(cin>>a){
    int b,c;
    while(a--){
        int b,c;    cin>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
}




return 0;
}
