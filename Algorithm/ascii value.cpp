#include <bits/stdc++.h>
using namespace std;
int main(){
  //  freopen("11340.txt","r",stdin);
int t;  cin>>t;
while(t--){
vector<string>v;
string s;
int n;
cin>>n;
vector<char> ch;
vector<float> cent;
for(int i=0;i<n;i++){
    char c; float d;
    cin>>c>>d;
    ch.push_back(c);
    cent.push_back(d);
}
int m;
cin>>m;
for(int i=0;i<=m;i++){
    getline(cin,s);
    v.push_back(s);
}
float ans=0;
for(int i=1;i<v.size();i++){
    string ss=v[i];
    for(int j=0;j<ss.size();j++){
    for(int k=0;k<ch.size();k++){
        if(ch[k]==ss[j]){
            ans+= cent[k];
            continue;
        }
    }
    }
}
printf("%.2f$\n",ans/100);


}
return 0;

}
