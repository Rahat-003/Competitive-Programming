#include <cstdio>

#include <queue>

#include <algorithm>

#include <memory.h>

//#define INF (int)1e7

using namespace std;
const int INF=99999;

struct node{
int x,y,z;
node(int _x,int _y,int _z){
x=_x,y=_y,z=_z;
}
};

int g[21][21];

int L[21][21][21];
int R,C,K;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void bfs(){
queue<node>q;
memset(L,INF,sizeof L);
L[0][0][0]=0;
q.push(node(0,0,0));

while(!q.empty()){
    int ux=q.front().x;
    int uy=q.front().y;
    int uk=q.front().z;
    q.pop();
    for(int i=0;i<4;i++){
        int nx=ux+dx[i];
        int ny=uy+dy[i];
        int nk;
        if(nx<0||ny<0||nx>=R||ny>=C)
            continue;
        if(g[nx][ny])
            nk=uk+1;
        else
            nk=0;
            if(nk>K)
                continue;
        if(L[nx][ny][nk]>L[ux][uy][uk]+1){
            q.push(node(nx,ny,nk));
            L[nx][ny][nk]=L[ux][uy][uk]+1;
        }
    }
}

int ans=INF;
for(int i=0;i<=K;i++)
    ans=min(ans,L[R-1][C-1][i]);
if(ans==INF)
    puts("-1");
else
    printf("%d\n",ans);

}

int main(){

int t;
scanf("%d",&t);
while(t--){
scanf("%d %d %d",&R,&C,&K);
for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
        scanf("%d",&g[i][j]);
bfs();
}

return  0;
}
