#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pp;
#define MAX 1003

int R,C;

int ar[MAX][MAX];
int vx[]={1,0,-1,0};
int vy[]={0,1,0,-1};

void bfs(int sx,int sy){
    queue<pp>q;
    q.push({sx,sy});
    ar[sx][sy] = 0;

    while(!q.empty()){
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = ux + vx[i];
            int ny = uy + vy[i];
            if(nx>=0 && nx<R && ny>=0 && ny<C && ar[nx][ny]==0){
                ar[nx][ny] = ar[ux][uy] + 1;
                q.push({nx,ny});
            }
          }
    }
}
int main(){
   /// freopen("10653.txt","r",stdin);
while(cin>>R>>C){
        if(R==0 && C==0) break;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            ar[i][j] = 0;
    int n;  cin>>n;
    while(n--){
        int r,x;  cin>>r>>x;
        while(x--){
            int a;  cin>>a;
            ar[r][a]= 1;
        }
    }

    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;
    bfs(sx,sy);
cout<<ar[dx][dy]<<endl;
}
return 0;
}
