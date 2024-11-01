#include <bits/stdc++.h>
using namespace std;

int main(){

string s,p;
while(cin>>s>>p){
int i,j;
int x=s.size();
int y=p.size();
for(i=0;i<x;i++){
    for(j=0;j<y && i+j<x;j++)
        if(s[i+j]!=p[j])    break;

    if(j==y)   { cout<<"Pattern found\n";
    break;
    }
    }
    if(j!=y) cout<<"Not found\n";




}


return 0;
}
