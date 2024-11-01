#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("12503.txt","r",stdin);
int t;
cin>>t;
int n=0;
while(t--){
        int total=0;
    vector<int>v;
    v.clear();
    v.push_back(0);
    int e;  cin>>e;
    while(e--){
    string s;
    cin>>s;
    if(s=="LEFT"){
        total-=1;   v.push_back(-1);
    }
    else if(s=="RIGHT"){
        total+=1; v.push_back(1);
    }
    else {
    string a;
    int b;
        cin>>a>>b;
        v.push_back(v[b]);
        total+=v[b];
    }
}
cout<<total<<endl;
}

return 0;
}
