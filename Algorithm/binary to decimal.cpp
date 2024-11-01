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

int Set(int n,int i){
	return n|=(1<<i);
}

int main(){
int t,tc = 0;

string s;
while(cin>>s){
	int ans = 0;
	int sz = s.size()-1;
	for(int i = sz; i>=0; i--)		if(s[i]=='1')	ans = Set(ans,sz-i);
	printf("%d\n",ans);
}

return 0;
}

