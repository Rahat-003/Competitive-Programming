#include <cstdio>
#define mx 5000001

int ar[mx+6];
int tot[mx+3];

void sieve(){

	tot[2] = 1;
//	/*
	for(int i = 3; i<mx; i++){
		if(i%2==0)	ar[i]+=2;
		if(!ar[i]){
			for(int j = i+i; j<mx; j+=i)
				ar[j]+=i;
		}
		tot[i] = tot[i-1] + (!ar[i]?1:((!ar[ar[i]])?1:0 ));
	}
//	*/
//	another optimization
/*
	for(int i = 3; i<mx; i+=2){
		ar[i+1]+=2;
		if(!ar[i]){
			for(int j = i+i; j<mx; j+=i)
				ar[j]+=i;
		}
		tot[i] = tot[i-1] + (!ar[i]?1:((!ar[ar[i]])?1:0 ));
		tot[i+1] = tot[i] + (!ar[i+1]?1:((!ar[ar[i+1]]?1:0)));
	}
//	*/
}



int main(){
int t,tc = 0;

sieve();
int a,b;
/*
while(1==scanf("%d",&a)){
	if(!a)	break;
	scanf("%d",&b);
	printf("%d\n",tot[b] - tot[a-1]);
}

/*
*/

return 0;
}

