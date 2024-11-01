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
#define mx 1000005

int z[mx];

void z_algo(string s,int sz){
    int x = 0,y = 0;
    for(int i = 1; i<s.size(); i++){
        z[i] = max(0,min(z[i-x],y-i+1));
        while( i+z[i]<s.size() && s[z[i]]==s[i+z[i]] ){
            x = i;  y=i+z[i];   z[i]++;
        }
    }
}

int main(){
string pat,txt;
//read;
while(cin>>pat>>txt){
    memset(z,0,sizeof z);
//    cin>>pat;
    int sz = pat.size();
    pat.push_back('#');
    cout<<sz<<endl;
    pat.append(txt);
    z_algo(pat,sz);
    for(int i = sz+1; i<pat.size(); i++)  cout<<z[i]<<" ";    cout<<endl;
}
//}



return 0;
}

