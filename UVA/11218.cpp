#include <cstdio>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
using namespace std;
typedef pair<int,int> pp;
pp ar[83];

bool check(int mask){
	if(mask==(1<<9)-1)	return true;
	return false;
}
bool fn(int mask,int i){
	return mask&=(1<<i);
}

int Set(int p,int i){
	return p|=(1<<i);
}
int n;

int fn(){
	int ans = -1;
	int mask = 0;
	for(int i = 0; i<n; i++){
		int t1 = mask;
		mask|=ar[i].first;
		for(int j = i+1; j<n; j++){
			int t2 = mask;
			mask|=ar[j].first;
			for(int k = j+1; k<n; k++){
				int t3 = mask;
				mask|=ar[k].first;
				if(check(mask))	ans = max(ans,ar[i].second + ar[j].second + ar[k].second );
				mask = t3;
			}
			mask = t2;
		}
		mask = t1;
	}
	return ans;
}

int main(){
int t,tc = 0;

while(1==scanf("%d",&n)){
	if(!n)	break;
	for(int i = 0; i<n; i++){
		int mask = 0,b;
		for(int j = 0; j<3; j++){
			int a;	scanf("%d",&a);	--a;
			mask = Set(mask,a);
		}
		scanf("%d",&b);
		ar[i] = {mask,b};
	}
	int ans = fn();
	case;
	printf("%d\n",ans);
}

return 0;
}

