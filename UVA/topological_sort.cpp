#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>mp(101);
bool visited[101];
stack<int>stk;

void dfs(int s){
visited[s]=true;
for(int i=0;i<mp[s].size();++i){
        int child = mp[s][i];
    if(!visited[child])
        dfs(child);
}
//cout<<s<<" ";
    stk.push(s);
}

int main(){

int n,e;
cin>>n>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
}


for(int i=0;i<n;i++){
    if(!visited[i])
        dfs(i);
}
while(!stk.empty()){
    cout<<stk.top()<<" ";
    stk.pop();
}
cout<<endl;
return 0;
}
