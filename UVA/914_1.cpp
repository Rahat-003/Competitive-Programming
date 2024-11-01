
#include <bits/stdc++.h>

using namespace std;

int main(){
int n;
cin>>n;
vector<int>v;
map<int,bool>vis;
while(n--){
    int a;
    cin>>a;
    v.push_back(a);
}
int mstrep=-1;
int rep = 0;
for(int i=0;i<v.size();i++){
    if( count( v.begin(),v.end(), v[i])>rep && vis[v[i]]==false ){
        mstrep=v[i];
        rep=count(v.begin(),v.end(),v[i]);
        vis[v[i]] = true;
        printf("(%d,%d) ",v[i],rep);
    }
}
//cout<<mstrep<<endl;
return 0;
}
