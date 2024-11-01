#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define mx 1000005
string s,t;
int lps[mx];

void make(){
    int k = 0;
    for(int i = 1; i<s.size(); i++){
        while(k && s[i]!=s[k])  k = lps[k-1];
        if(s[i]==s[k])  lps[i] = ++k;
    }
}

void search(){
    int k = 0,cnt = 0;

    for(int i = 0; i<t.size(); i++){
        while(k && s[k]!=t[i])  k = lps[k-1];
        if(s[k]==t[i])  k++;
        if(k==s.size()){
            cnt++;
            cout<<"Pattern found at "<<i-k+1<<endl;
            k = lps[k-1];
        }
    }
}

main(){
//read;

cin>>t>>s;
make();
search();

for(int i = 0; i<s.size(); i++)
    cout<<lps[i]<<" ";
cout<<endl;


return 0;
}
