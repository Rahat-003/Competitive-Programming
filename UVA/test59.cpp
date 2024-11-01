#include <bits/stdc++.h>
using namespace std;
#define MAX 10003
unordered_map<char,double> mp;
unordered_map<char,double> num;
int main(){
  //  freopen("11340_1.txt","r",stdin);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    while(n--){
       char c;
    double d;
    cin>>c>>d;
    mp[c] = d;
    num[c] = 0.0;
    }
    int m;
    cin>>m;
    cin.ignore();
    while(m--){
        char ar[MAX];
        gets(ar);
        int x=strlen(ar);
        for(int i=0;i<x;i++){
                int y=mp.count(ar[i]);
            if(y){
            num[ar[i]] += y;
            }
        }
    }
    double cnt=0;
    for(auto it=mp.begin(), itt=num.begin(); itt!=num.end(), it!=mp.end(); itt++, ++it)
        cnt+= it->second* itt->second;

        cout<<fixed<<setprecision(2)<<cnt/100.0<<"$"<<endl;
        mp.clear();
        num.clear();
}









return 0;
}
