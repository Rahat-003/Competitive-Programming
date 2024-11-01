#include <bits/stdc++.h>
using namespace std;

int  main(){
string s,p;
cin>>s>>p;
int i,j;
for(i=0;i<s.size();i++){
    for( j = 0; j<p.size() && i+j<s.size(); ++j)
        if(s[i+j]!= p[j]) break;

    if(p.size()==j) cout<<"Pattern found at index "<<i<<endl;

}



return 0;
}
