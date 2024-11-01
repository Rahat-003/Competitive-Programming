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
typedef vector<int> vi;

//  Longest Decreasing Subsequence:
//	just multiply every element of array with -1. And find LIS of the array;
// 	Or reverse the array and find LIS

//int ar[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
//int ar[] = {0,7,5,11,3,10,6,14,1,9,5,13,3,11,7,15};
//int ar[] = {1,3,4,3,3,3,4,5,6,4,5,4,5,5,5,6,6,6,6,7};
//int ar[] = {-7,10,9,2,3,8,8,6};
//int ar[] = {10,3,13,1,4};
vi ar = { 12 ,18 ,0 ,4 ,10 ,2 ,17 ,7 ,1 ,3 ,8 ,15 ,9 ,13 ,5 ,14 ,11 ,16 ,6 };
//vi ar = {10,3,13,1,4,9,8,12,6,14,5,7,2,0,11};
//vi ar = { 15, 27, 14, 38, 63, 55, 46, 65, 85};
//vi ar = {3,1,10,13,9,8,12,6,14,5,7,2,0,11};

int L[23],par[23];
vector<int> v;

int bs(int s,int len){
	int l = 0,h = len,m,i ;
	for( i = 0; i<50; i++){
		m = (l+h)/2;
		if(l==h)	break;
		ar[L[m]]>=s? h = m:l = m+1;
	}
	return m;
}

int LIS(){
	int len = 0,	sz = ar.size();	L[0] = 0;
//	for(int i = 0; i<sz; i++)	ar[i]*=-1;
//	reverse(ar.begin(),ar.end());
	for(int i = 1; i<sz; i++){
		if(ar[i]>ar[L[len]])		L[++len] = i,	par[i] = L[len-1];
		else if(ar[L[0]]>ar[i])		L[0] = i;
		else{
            int id = bs(ar[i],len);	L[id] = i;	par[i] = L[id-1];
		}
	}

	int x = L[len];
	while(x!=-1){
		v.push_back(ar[x]);
		x = par[x];
	}
	reverse(v.begin(),v.end());
	return len+1;
}

int main(){
int t,tc = 0;
memset(par,-1,sizeof par);
cout<<LIS()<<endl;

for(int i:v)	cout<<i<<" ";
cout<<endl;

return 0;
}

