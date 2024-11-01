#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 1000004


int ar[mx],n;
string s,t;

void fn(){
    int j = 0;
    for(int i = 1; i<n; i++){
        if(s[i]==s[j]){
            ar[i] = ++j;
            continue;
        }
        while(s[i]!=s[j] && j)  j = ar[j-1];
        if(s[i]==s[j]) ar[i] = ++j;
        else ar[i] = 0;
    }
}

void kmp(){
    int j = 0,i = 0;
    int cnt = 0;
    while(i<t.size()){
        if(t[i]==s[j])  i++,j++;
        if(j==n){
            printf("found at %d\n",i-n);
            j = ar[n-1];
            cnt++;
        }
        else if(t[i]!=s[j]){
            if(j)   j = ar[j-1];
            else i++;
        }
    }
}

main(){
//read;

cin>>t>>s;
n = s.size();
fn();
kmp();



return 0;
}
