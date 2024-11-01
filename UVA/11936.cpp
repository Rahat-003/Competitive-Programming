#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;



int main(){
int t;
cin>>t;
while(t--){
	vector<int> v;
	for(int i = 0; i<3; i++){
		int a;	cin>>a;	v.push_back(a);
	}
	sort(v.begin(),v.end());
	if(v[0]+v[1]>v[2]){
		puts("OK");
	}
	else puts("Wrong!!");
	v.clear();
}


return 0;
}

