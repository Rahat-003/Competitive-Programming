#include <iostream>
#include <cstdio>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

//int ar[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
//int ar[] = {0,7,5,11,3,10,6,14,1,9,5,13,3,11,7,15};
//int ar[] = {1,3,4,3,3,3,4,5,6,4,5,4,5,5,5,6,6,6,6,7};
//int ar[] = {-7,10,9,2,3,8,8,6};

//int L[23],par[23];
vector<int> v,ar,L,par;

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
string s;
while(getline(cin,s)){
	if(!s.size())	break;
	int p;
	stringstream iss(s);
	iss>>p;
	ar.push_back(p);
}
int sz = ar.size();
L = vector<int> (sz);
par = vector<int> (sz,-1);
cout<<LIS()<<endl;
puts("-");

for(int i = 0; i<v.size(); i++)
	printf("%d\n",v[i]);


return 0;
}

