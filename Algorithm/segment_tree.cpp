
#include <bits/stdc++.h>
using namespace std;
#define mx (int)1e5+3
int ar[mx];
int tree[mx*3];

void init(int node,int b,int e){
	if(b==e){
		tree[node] = ar[b];
		return;
	}
	int left = 2*node;
	int right = left+1;
	int mid = (b+e)/2;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node] = tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j){
	if(i>e || j<b)	return 0;
	if(b==e){
		return tree[node];
	}
	
	int left = node*2;
	int right = left+1;
	int mid = (b+e)/2;
	int p1 = query(left,b,mid,i,j);
	int p2 = query(right,mid+1,e,i,j);
	return p1+p2;
}

void update(int node,int b,int e,int i,int j,int n){
	if(i>e || j<b)	return;
	if(b==e){
//		ar[b] = n
		tree[node] = n;
		return;
	}
	int left = node*2;
	int right = left+1;
	int mid = (b+e)/2;
	update(left,b,mid,i,j,n);
	update(right,mid+1,e,i,j,n);
	tree[node] = tree[left] + tree[right];
}

void print(){
	for(int i = 1; i<10; i++)
	if(tree[i])	cout<<tree[i]<<" ";
	cout<<endl;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%d",&ar[i]);
	}
	
	init(1,0,n-1);
	print();
	
	int x =	query(1,0,n-1,0,1);
	cout<<x<<endl;
	update(1,0,n-1,0,0,4);
	print();
	
return 0;
}
