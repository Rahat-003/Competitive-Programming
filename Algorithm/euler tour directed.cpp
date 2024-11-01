#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v,graph;
vector<bool> vis;
vector<int> indeg,outdeg;
int n,e;

int dfs(int a){
    int cnt = 1;
    vis[a] = 1;
    for(auto child:graph[a]){
        if(child!=-1 && vis[child]==false)
            cnt+=dfs(child);
    }
    return cnt;
}

void rem(int a,int b){
    auto it = find(v[a].begin(),v[a].end(),b);
    *it = -1;
}

void rem2(int a,int b,auto &v){
    auto it = find(v[a].begin(),v[a].end(),b);
    *it = -1;
    auto jt = find(v[b].begin(),v[b].end(),a);
    *jt = -1;
}

void add2(int a,int b){
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool isPath(int a,int b){
    int cnt = 0 , cnt1,cnt2;

    for(int i = 0 ; i<v[a].size(); i++){
        if(v[a][i]!=-1) cnt++;
    }
    if(cnt==1)  return true;

    vis.assign(n,false);
    cnt1 = dfs(a);

    rem2(a,b,graph);

    vis.assign(n,false);
    cnt2 = dfs(b);

    add2(a,b);
    if(cnt1>cnt2)   return 0;


    return 1;
}

void print(int a){
    for(int i = 0 ; i<v[a].size(); i++){
        int child = v[a][i];
        if(child!=-1 && isPath(a,child)){
            cout<<a<<"--"<<child<<" ";
            rem(a,child);
            rem2(a,child,graph);
            print(child);
        }

    }
}


void Euler(){
    int p = -1,c = -1;
    int r = 0,s = 0;

    bool x,y;

    for(int i = 0 ; i<n; i++){
        if(indeg[i]==outdeg[i]){
        r++;
        }

        if( abs(indeg[i]-outdeg[i])==1 )  s++;
    }

    if( n-r>2 || r+s!=n ) {
        puts("Not Eulerian");
        return ;
    }

    int cnt = 0;

    int a = 0,b = 0;

    for(int k = 0 ; k<n; k++){

        if(outdeg[k] - indeg[k] == 1 ){
            p = k;
            cout<<"Eulerian Path\n";
            print(p);
            puts("");
            return;
        }

        if(indeg[k]==outdeg[k]){
            a++;
            c = k;
        }

    }

//    if(a!=n && p==-1)

    cout<<"Eulerian Cycle\n";
    if(c!=-1 && p==-1)   print(c);
    cout<<endl;
}

int main(){
cin>>n>>e;
v.assign(n,vector<int>());
vis.assign(n,false);
indeg.assign(n,0);
outdeg = indeg;

graph = v;

while(e--){
        int a,b;
        cin>>a>>b;
    indeg[b]++;
    outdeg[a]++;
    v[a].push_back(b);

    graph[a].push_back(b);
    graph[b].push_back(a);
}

Euler();





}
