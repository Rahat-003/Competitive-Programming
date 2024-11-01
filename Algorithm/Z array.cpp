
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

vector<int> z;

void z_algo(string s){
    z.assign(s.size(),0);
    int x = 0,y = 0,cnt = 0;

    for(int i = 1; i<s.size(); i++){
        z[i]= max(0,min(z[i-x],y-i+1));
        while( i+z[i]<s.size() && s[z[i]]==s[i+z[i]]){
        x = i,y = i+z[i],   z[i]++;
        }
    }
}

int main(){
int t,tc = 0;
string s;

while(cin>>s){
    z_algo(s);
    for(int i:z)    cout<<i<<" ";
    puts("");
}



return 0;
}

