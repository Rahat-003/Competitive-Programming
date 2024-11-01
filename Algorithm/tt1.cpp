#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <queue>

#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
#define pi acos(-1)


priority_queue<int,std::vector<int> ,less<int> > pq;
std::vector<int> v;

main(){

read;
write;

int x;
cin>>x;
cout<<x<<endl;
for(int i = 0; i<x; i++){
	pq.push(i);
	v.push_back(i);
}	

while(!pq.empty()){
	cout<<pq.top()<<" ";
	pq.pop();
}
cout<<endl;
for(auto i:v)	cout<<i<< " ";	cout<<endl;

for(auto i:v)
printf("%2d ", i);

return 0;
}