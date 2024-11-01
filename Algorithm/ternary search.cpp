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

vector<int> ar = {1,5,7,9,13,19};

int x;
int fn(int l,int h){
	if(l<=h){
	int m1,m2;

        m1 = l+(h-l)/3;
        m2 = h-(h-l)/3;

	/**
	m1 = (2*l+h)/3;     Never use this value of m1 and m2
	m2 = (2*h+l)/3;
    **/
	if(ar[m1]==x)	return m1;
	if(ar[m2]==x)	return m2;

	if(ar[m1]>x)		return fn(l,m1-1);
	else if(ar[m2]<x)	return fn(m2+1,h);
	else  /*if(ar[m1]<x && x<ar[m2])*/				return fn(m1+1,m2-1);
	}
	cout<<l<<" "<<h<<endl;

return -1;
}


void iterative(){
    /**
        check this approach
        https://codeforces.com/contest/1928/submission/245910546
    */
}


int main(){
int t,tc = 0;

int n;
	int sz = ar.size();
while(1==scanf("%d",&x)){
	int id = fn(0,sz-1);
	printf("%d\n",id);
}


return 0;
}

