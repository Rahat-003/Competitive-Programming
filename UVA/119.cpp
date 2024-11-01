#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;

int main(){
        //freopen("119.txt","r",stdin);
int n;
int c=0;
while(cin>>n){
        vector<string>v;
    mp.clear();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]=0;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        string a;
        int x,y;
        cin>>a>>x>>y;
        if(y!=0){
        mp[a]-=(x-(x%y));
        }
        if(y==0){
            mp[a]-=0;
        }

    for(int i=0;i<y;i++){
            string b;
        cin>>b;
        if(x==0) mp[b]+=0;
        else
        mp[b]+=(x/y);
    }
}
if(c>0) cout<<endl; c++;
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" "<<mp[v[i]]<<endl;
}

return 0;
}
