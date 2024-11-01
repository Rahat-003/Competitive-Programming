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
vector<int> ar = {1,3,5},v;

void sub(int l,int sum){
    if(l==ar.size()){
        v.push_back(sum);
    return;
    }
    sub(l+1,sum+ar[l]);
    sub(l+1,sum);
}

int main(){
int t,tc = 0;
sub(0,0);
for(auto i:v)   cout<<i<<" ";
puts("");
cout<<v.size()<<endl;

return 0;
}

