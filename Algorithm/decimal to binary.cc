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
bool check(int n,int i){
	return n&=(1<<i);
}


int main(){
int t,tc = 0;
int n;

while(1==scanf("%d",&n)){
	string s;
	bool fl = !n;
	int id = 31;
	if(!n)	id = 0;

	for(int i = id; i>=0 ; i--)	{
		if(check(n,i))	fl = true;
		if(fl){
			if(check(n,i))	s.push_back('1');
			else s.push_back('0');
		}
	}
	cout<<s<<endl;

}

return 0;
}

