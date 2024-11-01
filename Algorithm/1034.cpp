#include <bits/stdc++.h>

using namespace std;
map<int,vector<int>>mp;
set<int>visited;
stack<int>stk;
void dfs(int s){
visited.insert(s);
vector<int>::iterator it;
for(it=mp[s].begin();it!=mp[s].end();++it)
    if(visited.find(*it)==visited.end())
        dfs(*it);

}

void topology(int s){
visited.insert(s);
vector<int>::iterator it;
for(it=mp[s].begin();it!=mp[s].end();++it)
    if(visited.find(*it)==visited.end())
        topology(*it);
stk.push(s);
}

int main(){

int t;
cin>>t;
int k=0;
while(t--){
        mp.clear();
        visited.clear();
   int n,e;
   cin>>n>>e;
   for(int i=1;i<=n;i++)
        mp[i];
   while(e--){
    int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
   }
   for(int i=1;i<=n;i++)
    if(visited.find(i)==visited.end())
        topology(i);
   visited.clear();
   int cnt=0;
   while(!stk.empty()){
    int u=stk.top();
    stk.pop();
    if(visited.find(u)==visited.end())
    {
        dfs(u);
        cnt++;
    }
   }
    cout<<"Case "<<++k<<": "<<cnt<<endl;
}
return 0;
}
