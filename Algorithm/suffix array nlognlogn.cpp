#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

struct suffix{
    int r1,r2,id;
    bool operator < (const suffix &n)   const{
        if(r1!=n.r1)    return r1<n.r1;
        return r2<n.r2;
    }
};
string s;
void suffixArray(){
    int sz = s.size();
    suffix ar[sz];
    for(int i = 0; i<sz; i++){
        ar[i].id = i;
        ar[i].r1 = s[i] - 'a';
        ar[i].r2 = (i+1<sz) ? s[i+1] - 'a' : -1;
    }
    sort(ar,ar+sz);
    int ind[sz];
    for(int k = 4; k<2*sz; k*=2){
        int prev = ar[0].r1,    rank = 0;
        ind[ar[0].id] = 0;
        ar[0].r1 = 0;
        for(int i = 1; i<sz; i++){
            if(ar[i].r1==prev && ar[i].r2==ar[i-1].r2){
                prev = ar[i].r1;
                ar[i].r1 = rank;
            }
            else{
                prev = ar[i].r1;
                ar[i].r1 = ++rank;
            }

            ind[ar[i].id] = i;
        }
        for(int i = 0; i<sz; i++){
            int nxt = ar[i].id+k/2;
            ar[i].r2 = (nxt<sz) ? ar[ind[nxt]].r1 : -1;
        }
        sort(ar,ar+sz);
    }
    for(int i = 0; i<sz; i++)
        cout<<ar[i].id<<" ";
    puts("");
}


void suffix_array(){
    // same
    int rank,prev,n = s.size(),ind[n];
    suffix ar[n];
    for(int i = 0; i<n; i++)        ar[i] = {s[i],i+1<n?s[i+1]:-1,i};
    sort(ar,ar+n);
    for(int k = 4; k<2*n; k*=2){
        rank = 0,prev = ar[0].r1,ind[ar[0].id] = 0,ar[0].r1 = 0;
        for(int i = 1; i<n; i++)
            rank+=prev!=ar[i].r1||ar[i].r2!=ar[i-1].r2,prev=ar[i].r1,ar[i].r1=rank,ind[ar[i].id] = i;
        for(int i = 0,j; i<n; i++)
            j = ar[i].id + k/2, ar[i].r2 = j<n?ar[ind[j]].r1:-1;
        sort(ar,ar+n);
    }
    for(int i = 0; i<n; i++)        cout<<ar[i].id<<" ";    cout<<endl;
}



int main(){
int t,tc = 0;

//s = "banana";

while(cin>>s){

suffixArray();
suffix_array();

}

return 0;
}

