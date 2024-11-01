#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int,int>pp;
char MAT[21][21];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int C,R;
int graph[21][21];
void bfs(int sx,int sy){
queue<pp>q;
q.push(pp(sx,sy));
graph[sx][sy]=0;
while(!q.empty()){

    pp u=q.front();
    q.pop();
    for(int i=0;i<4;i++){
        int nx=u.first+dx[i];
        int ny=u.second+dy[i];
        if(nx>=0&&nx<R&&ny>=0&&ny<C&&graph[nx][ny]==-1){
            graph[nx][ny]=0;
            q.push(pp(nx,ny));
        }
    }
}

}

int main(){
int t;
cin>>t;
for(int i=1;i<=t;i++){
        memset(graph,-1,sizeof(graph));
cin>>C>>R;
int sx,sy;
for(int k=0;k<R;k++)
{
    for(int j=0;j<C;j++){
        cin>>MAT[k][j];
        if(MAT[k][j]=='#')
            graph[k][j]=-2;
        if(MAT[k][j]=='@')
            sx=i,sy=j;

    }
}
bfs(sx,sy);

int cnt=0;
for(int k=0;k<R;k++){
    for(int j=0;j<C;j++){
        if(graph[k][j]==0)
            cnt++;
    }
}
cout<<"Case "<<i<<": "<<cnt<<endl;
}

return 0;
}
