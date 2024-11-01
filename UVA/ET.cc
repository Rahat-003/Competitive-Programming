#include <cstdio>

#include <queue>

#include <memory.h>

using namespace std;
int R,C;
char g[305][305];
bool vis[305][305][3];
int x,y;

struct node{
int x,y,z;
node(){};
node(int _x,int _y,int _z){
x=_x,y=_y,z=_z;
}
};

int ans;
bool f1;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(){

queue<node>q;
memset(vis,false,sizeof vis);
vis[x][y][0]=true;
int nx,ny;

bool f2;
q.push(node(x,y,0));

while(!q.empty()){
    node fr=q.front();
    q.pop();
    if(g[fr.x][fr.y]=='E'){
        f1=true;
        printf("%d\n",fr.z);
        break;
    }
    for(int i=0;i<4;i++){
        nx=fr.x,ny=fr.y;
        f2=true;
        for(int j=(fr.z)%3;j>=0;j--){
            nx+=dx[i],ny+=dy[i];
            if(nx==-1||ny==-1||nx==R||ny==C||g[nx][ny]=='#'){
                f2=false;
                break;
            }
        }
        if(f2&&!vis[nx][ny][(fr.z+1)%3]){
            vis[nx][ny][(fr.z+1)%3]=true;
            q.push(node(nx,ny,fr.z+1));
        }
    }

}
}

int main(){

int t;
scanf("%d",&t);
while(t--){

    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++)
        scanf("%s",g[i]);
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
    if(g[i][j]=='S'){
        x=i,y=j;
    }
     f1=false;
    bfs();

    if(!f1)

        puts("NO");
}


return 0;
}
