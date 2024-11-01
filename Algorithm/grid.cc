#include<cstdio>

#include <algorithm>
int r,c;
int MAT[101][101];
int sol[101][101];
bool safe(int x,int y){
return (x>=0&&y>=0&&x<r&&y<c&&MAT[x][y]==1);
}
bool solution(int x,int y){
if(x==r-1&&y==c-1){
    sol[x][y]=1;
    return true;
}
if(safe(x,y)){
    sol[x][y]=1;
    if(solution(x+1,y))
        return true;
    if(solution(x,y+1))
        return true;
    sol[x][y]=0;
}
return false;
}

void print(){

for(int i=0;i<r;i++){

    for(int j=0;j<c;j++)
        printf("%d ",sol[i][j]);
    puts("");
}
}

void solve(int x,int y){
for(int i=0;i<x;i++)
    std::fill(sol[i],sol[i]+c,0);
if(!solution(x,y))
    printf("no path\n");
else
    print();
}


int main(){
scanf("%d %d",&r,&c);
for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
        scanf("%d",&MAT[i][j]);
solve(0,0);

return 0;
}
