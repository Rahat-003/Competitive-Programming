#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 100000



int main(){
int t,tc = 0;
write;
puts("1");
string s;
for(int i = 0; i<mx; i++)
    if(i&1) s.push_back('1');
    else s.push_back('0');
cout<<s<<endl<<mx/2<<endl;

for(int i = 0; i<mx/4; i++) puts("I 1 100000");
for(int i = 0; i<mx/4; i++) printf("Q %d\n",i+1);

return 0;
}

