#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <set>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
//#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

string s;
int ar[30];

int fn(){
    int ans = s.size();
    for(int i = 0; i<26; i++)
        ans = min(ans,ar[i]);
    return ans;
}

main(){

int t,tc = 0;

scanf("%d",&t);

while(t--){

    memset(ar,0,sizeof ar);
    cin>>s;
    for(int i = 0; i<s.size(); i++){
        int id = s[i] - 'a';
        ar[id]++;
    }
    case;
    cout<<fn()<<endl;
}



return 0;
}
