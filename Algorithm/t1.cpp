
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

#define mx 1000005

bool ar[mx];
// int prime[mx];

int dis[mx];


void sieve(){
  // memset(ar,false,sizeof ar);
   ar[0] = ar[1] = true;

  for(int i = 3; i*i<=mx; i+=2){
    if(!ar[i]){
      for(int j = i*i; j<mx; j+=2*i)
        ar[j] = true;
    }
  }
  // int x = 0;
  // prime[x] = 2;
  dis[2] = 0;
  int y = 2;

  for(int i = 3;i<mx;i+=2)

  if(!ar[i]){
    // prime[++x] = i;
    dis[i] = i - y;
    y = i;
  }


}


int main(int argc, char const *argv[]) {

sieve();
int t;

scanf("%d",&t );

while(t--){
int a,b;
scanf("%d %d",&a,&b);
int i,tmp;

for(i = a;i<=b;i++){
  if(!ar[i] && (i&1 || i==2)){
    tmp = dis[a];
    dis[a] = 0;
    break;
  }
}

bool fl = false;
int mx = -1;
int mn =











/*
map<int,int> mp;
for(int j = i+1; j<=b; j++ ){
  if( (j&1 || j==2) &&  !ar[j]){
    int y = dis[j];
    mp[y]++;
    fl = true;
  }
}
int ans = -1, id;
int cnt = 0;

for(auto it = mp.begin(); it!=mp.end(); it++){
  if(it->second > ans){
    ans = it->second;
    id = it->first;
    cnt = 0;

  }
  else if(it->second == ans) cnt++;
}

if(!fl || cnt)  puts("No jumping champion");
else printf("The jumping champion is %d\n",id );
*/
 dis[a] = tmp;
}
  return 0;
}
