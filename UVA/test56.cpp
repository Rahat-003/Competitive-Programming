#include <bits/stdc++.h>
using namespace std;
map<string,vector<string>> mp;
int main(){
string a,b;
cin>>a>>b;
mp[a].push_back(b);
mp[b].push_back(a);


for(auto it=mp.begin();it!=mp.end();++it){
    cout<<it->first<<" ";

    for(auto i=it->second.begin();i!=it->second.end();++i)
        cout<<*i<<" ";
    cout<<endl;
}



return 0;
}
