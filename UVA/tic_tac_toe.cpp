#include <memory.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using namespace std;
int flag = 0;
char ar[4][4];
bool vis[10];
bool check(int r,int c){
	if(ar[0][0]==ar[1][1] && ar[1][1]==ar[2][2])	return true;
	if(ar[0][2]==ar[1][1] && ar[1][1]==ar[2][0])	return true;
	if(ar[r][0]==ar[r][1] && ar[r][1]==ar[r][2])	return true;
	if(ar[0][c]==ar[1][c] && ar[1][c]==ar[2][c])	return true;
	return false;
}
int print(int n){
	system("cls");
	printf("\n");
	printf("     |     |\n");
   printf("  %c  |  %c  |  %c  \n",ar[0][0],ar[0][1],ar[0][2]);
	printf("_____|_____|_____\n");
	printf("     |     |\n");
   printf("  %c  |  %c  |  %c  \n",ar[1][0],ar[1][1],ar[1][2]);
	printf("_____|_____|_____\n");
	printf("     |     |\n");
   printf("  %c  |  %c  |  %c  \n",ar[2][0],ar[2][1],ar[2][2]);
	printf("     |     |\n\n");

	printf("Greetings From This Machine: ");
	if(n==9)	printf("Well played.\n\n");
	if(flag==1)	puts("Choose a number from 1 to 9.\n");
	if(flag==2)	puts("This Move was taken earlier\n");
	if(n%2==0)	n=0;
	if(n&1)	n = 1;
return n+1;
}

void rc(int n,int &r,int &c){
	n-=1;
	r = n/3;
	c = n-3*r;
	return;
}

void ini(){
	for(int i = 1; i<=9; i++){
		int r,c;
		rc(i,r,c);
//		ar[r][c] = i+'0';
        ar[r][c] = ' ';

	}
}

int main(){

ini();
vis[0] = true;
print(0);
int move;
bool fl = false;
for(int i = 0; i<=9; i++){
	move = print(i);
	if(i==9)	break;
	if(!flag)	puts("\n");
	printf("Player %d move: ",move);
	char c;
	if(move==1)	c = 'O';
	else c = 'X';
	int n,R,C;
	scanf("%d",&n);
	if(n>9 || n<1){
		flag = 1;
		i--;
		continue;
	}
	if(vis[n]){
		flag = 2;
		--i;	continue;
	}
	vis[n] = true;
	flag = 0;
	rc(n,R,C);
	ar[R][C] = c;

	if(check(R,C)){
		print(i);
		int w,l;	w = move;
		if(w==1)	l = 2;
		else l = 1;
		printf("Congratulation Player %d.\n\n",w);
		fl = true;
		break;
	}
}
printf("Result: ");
if(fl)	printf("Player %d WON\n",move);
else puts("DRAW");
return 0;
}

